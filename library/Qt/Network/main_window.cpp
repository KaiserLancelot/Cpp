//
// Created by kaiser on 19-4-11.
//

#include "main_window.h"

#include <QComboBox>
#include <QEventLoop>
#include <QJsonDocument>
#include <QLabel>
#include <QNetworkReply>
#include <QPixmap>
#include <QPushButton>
#include <QVBoxLayout>
#include <QVariantList>
#include <QVariantMap>
#include <QWidget>

#include "weather_info.h"

MainWindow::MainWindow() {
  auto city_list{new QComboBox{this}};
  city_list->resize(200, 50);
  city_list->addItem(tr("Beijing"), QLatin1String("Beijing,cn"));
  city_list->addItem(tr("Shanghai"), QLatin1String("Shanghai,cn"));
  city_list->addItem(tr("Shenyang"), QLatin1String("Shenyang,cn"));

  auto city_label{new QLabel{tr("City"), this}};
  auto refresh_button{new QPushButton{tr("Refresh"), this}};

  auto city_layout{new QHBoxLayout};
  city_layout->addWidget(city_label);
  city_layout->addWidget(city_list);
  city_layout->addWidget(refresh_button);

  auto city_name_label{new QLabel{this}};
  auto data_time_label{new QLabel{this}};

  auto weather_layout{new QVBoxLayout};
  weather_layout->addWidget(city_name_label);
  weather_layout->addWidget(data_time_label);
  // decl and icon
  weather_layout->addWidget(new QLabel{this});
  weather_layout->addWidget(new QLabel{this});

  auto main_widget{new QWidget{this}};
  auto main_layout{new QVBoxLayout{main_widget}};
  main_layout->addLayout(city_layout);
  main_layout->addLayout(weather_layout);

  setCentralWidget(main_widget);
  resize(800, 600);
  setWindowTitle(tr("Weather"));

  connect(net_worker_, &NetWorker::Finished,
          [city_name_label, data_time_label, weather_layout,
           this](QNetworkReply* reply) {
            switch (reply_.value(reply)) {
              case ReplyType ::kWeather: {
                auto document{QJsonDocument::fromJson(reply->readAll())};
                auto data{document.toVariant().toMap()};

                WeatherInfo weather_info;

                // name -- 城市名
                weather_info.SetCityName(data["name"].toString());

                QDateTime date_time;
                // dt -- 从 1970.1.1 开始到现在的秒数
                date_time.setTime_t(data["dt"].toLongLong());
                weather_info.SetDateTime(date_time);

                // main -- 包含温度, 压强, 湿度以及最高和最低温度
                auto main{data["main"].toMap()};
                weather_info.SetTemperature(main["temp"].toDouble());
                weather_info.SetPressure(main["pressure"].toDouble());
                weather_info.SetHumidity(main["humidity"].toDouble());

                QVariant detail;
                // weather -- 包含 天气的描述和图标(该网站上的一个图片)等
                // 注意下面的初始化不能使用花括号, QList 有一个接受
                // std::initializer_list 的参数
                if (auto list = data["weather"].toList(); !list.isEmpty()) {
                  detail = list.at(0);
                }

                auto map{detail.toMap()};
                weather_info.SetDesc(map["description"].toString());
                weather_info.SetIcon(map["icon"].toString());

                FetchIcon(weather_info.GetIcon());

                dynamic_cast<QLabel*>(weather_layout->itemAt(2)->widget())
                    ->setText(weather_info.GetDesc() + " " +
                              QString::number(weather_info.GetTemperature()) +
                              "°C");

                city_name_label->setText(weather_info.GetCityName());
                data_time_label->setText(weather_info.GetDateTime().toString(
                    Qt::DefaultLocaleLongDate));
              } break;
              case ReplyType ::kIcon: {
                QPixmap pixmap;
                pixmap.loadFromData(reply->readAll());

                dynamic_cast<QLabel*>(weather_layout->itemAt(3)->widget())
                    ->setPixmap(pixmap);
              } break;
              default:;
            }
            // 当网络请求结束时, delete 服务器返回的 QNetworkReply
            // 对象是用户的责任 但是如果一个槽函数连接到 error() / finished(),
            // 则不能 delete 槽函数中的 QNetworkReply 对象, 应该使用
            // deleteLater()
            reply->deleteLater();
          });

  connect(refresh_button, &QPushButton::clicked, [city_list, this] {
    FetchWeather(city_list->itemData(city_list->currentIndex()).toString());
  });
}

void MainWindow::FetchWeather(const QString& city_name) {
  QEventLoop event_loop;
  // 注意, 非 GUI 程序中另外启动事件循环会将主线程阻塞, QNetworkAccessManager
  // 的所有信号都不会收到, 这并不是一个好的做法
  connect(net_worker_, &NetWorker::Finished, &event_loop, &QEventLoop::quit);

  // http://api.openweathermap.org/data/2.5/weather?q=BeiJing,cn&mode=json&units=metric&lang=zh_cn&APPID=6b55db98c0b1a112f1f98bd93e4726ac
  auto reply{net_worker_->Get(
      QString{"http://api.openweathermap.org/data/2.5/"
              "weather?q=%1&mode=json&units=metric&lang=zh_cn&APPID="
              "6b55db98c0b1a112f1f98bd93e4726ac"}
          .arg(city_name))};
  reply_.insert(reply, ReplyType::kWeather);

  event_loop.exec();
}

void MainWindow::FetchIcon(const QString& icon_name) {
  QEventLoop event_loop;
  connect(net_worker_, &NetWorker::Finished, &event_loop, &QEventLoop::quit);

  // http://openweathermap.org/img/w/10d.png
  auto reply{net_worker_->Get(
      QString{"http://openweathermap.org/img/w/%1.png"}.arg(icon_name))};
  reply_.insert(reply, ReplyType::kIcon);

  event_loop.exec();
}
