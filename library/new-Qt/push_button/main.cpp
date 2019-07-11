//
// Created by kaiser on 19-7-11.
//

#include <QApplication>

#include "main_window.h"

int main(int argc, char *argv[]) {
  QApplication app{argc, argv};

  MainWindow main_window;
  main_window.show();

  QApplication::exec();
}
