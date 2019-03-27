//
// Created by kaiser on 19-3-27.
//

#include "paint_device.h"

#include <QApplication>

int main(int argc, char *argv[]) {
  QApplication app{argc, argv};

  PaintDevice paint_device;
  paint_device.show();

  return QApplication::exec();
}