//
// Created by kaiser on 19-7-11.
//

#include <QApplication>
#include <QTranslator>

#include "main_Widget.h"

int main(int argc, char *argv[]) {
  QApplication app{argc, argv};

  MainWidget main_window;
  main_window.show();

  QApplication::exec();
}
