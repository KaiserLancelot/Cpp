//
// Created by kaiser on 19-3-27.
//

#include "coordinate.h"

#include <QApplication>

int main(int argc, char *argv[]) {
  QApplication app{argc, argv};

  Coordinate coordinate;
  coordinate.show();

  return QApplication::exec();
}
