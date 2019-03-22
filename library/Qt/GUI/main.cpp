//
// Created by kaiser on 19-3-22.
//

#include <QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  MainWindow w;
  w.show();

  return QApplication::exec();
}