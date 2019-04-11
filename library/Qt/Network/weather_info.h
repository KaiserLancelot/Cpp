//
// Created by kaiser on 19-4-11.
//

#ifndef CPP_STUDY_LIBRARY_QT_NETWORK_WEATHER_INFO_H_
#define CPP_STUDY_LIBRARY_QT_NETWORK_WEATHER_INFO_H_

#include <QDateTime>
#include <QList>
#include <QString>

class WeatherInfo {
 public:
  QString GetCityName() const;
  void SetCityName(const QString &city_name);

  QDateTime GetDateTime() const;
  void SetDateTime(const QDateTime &date_time);

  double GetTemperature() const;
  void SetTemperature(double temperature);

  double GetHumidity() const;
  void SetHumidity(double humidity);

  double GetPressure() const;
  void SetPressure(double pressure);

  QString GetDesc() const;
  void SetDesc(const QString & desc);

  QString GetIcon() const;
  void SetIcon(const QString & icon);

 private:
  QString city_name_;
  QDateTime date_time_;
  // 温度
  double temperature_{};
  // 湿度
  double humidity_{};
  // 压强
  double pressure_{};
  QString desc_;
  QString icon_;
};

#endif  // CPP_STUDY_LIBRARY_QT_NETWORK_WEATHER_INFO_H_
