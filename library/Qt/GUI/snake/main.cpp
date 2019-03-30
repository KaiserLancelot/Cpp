//
// Created by kaiser on 19-3-30.
//

#include <QApplication>

#include "main_window.h"

int main(int argc, char *argv[]) {
  QApplication app{argc, argv};
  QApplication::setWindowIcon(QIcon{":/images/snake_ico"});

  MainWindow window;
  window.show();

  return QApplication::exec();
}