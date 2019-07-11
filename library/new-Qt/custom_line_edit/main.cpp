//
// Created by kaiser on 19-7-11.
//

#include <QApplication>

#include "main_widget.h"

int main(int argc, char *argv[]) {
  QApplication app{argc, argv};

  MainWidget main_widget;
  main_widget.show();

  QApplication::exec();
}
