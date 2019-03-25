//
// Created by kaiser on 19-3-25.
//

#include "accept_ignore2.h"

#include <QApplication>

int main(int argc, char *argv[]) {
  QApplication app{argc, argv};

  MainWindow window;
  window.show();

  return QApplication::exec();
}