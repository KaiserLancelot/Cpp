//
// Created by kaiser on 19-4-10.
//

#include <QApplication>

#include "main_window.h"

int main(int argc, char *argv[]) {
  QApplication app{argc, argv};

  MainWindow window;
  window.show();

  return QApplication::exec();
}
