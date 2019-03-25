//
// Created by kaiser on 19-3-25.
//

#include "event.h"

#include <QApplication>

int main(int argc, char *argv[]) {
  QApplication app{argc, argv};

  CustomWidget widget;
  widget.setMinimumSize(600, 400);
  widget.show();

  return QApplication::exec();
}