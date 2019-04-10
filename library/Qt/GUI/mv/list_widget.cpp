//
// Created by kaiser on 19-4-10.
//

#include <QApplication>
#include <QHBoxLayout>
#include <QLabel>
#include <QListWidget>
#include <QObject>

int main(int argc, char *argv[]) {
  QApplication app{argc, argv};

  QWidget widget;

  widget.resize(800, 600);

  auto label{new QLabel{&widget}};
  // 设置固定大小
  label->setFixedWidth(400);

  auto list_widget{new QListWidget{&widget}};

  // 添加到末尾. 还可以使用 insertItem 添加到指定位置
  list_widget->addItem(
      new QListWidgetItem(QIcon(":images/copy.png"), QObject::tr("Copy")));
  list_widget->addItem(
      new QListWidgetItem(QIcon(":images/cut.png"), QObject::tr("Cut")));
  list_widget->addItem(
      new QListWidgetItem(QIcon(":images/new.png"), QObject::tr("New")));

  // 改变显示方式
  // list_widget->setViewMode(QListView::IconMode);

  auto layout = new QHBoxLayout;
  layout->addWidget(label);
  layout->addWidget(list_widget);

  widget.setLayout(layout);

  QObject::connect(list_widget, &QListWidget::currentTextChanged, label,
                   &QLabel::setText);

  widget.show();

  QApplication::exec();
}
