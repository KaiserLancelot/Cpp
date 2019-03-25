//
// Created by kaiser on 19-3-22.
//

#include <QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[]) {
  // 必须首先创建它, 用于管理 Qt 程序的生命周期, 开启事件循环等
  // 对于非 GUI 程序, QCoreApplication 不是必不可少的
  QApplication a{argc, argv};

  MainWindow w;
  w.show();

  // 程序将进入事件循环来监听应用程序的事件
  return QApplication::exec();
}