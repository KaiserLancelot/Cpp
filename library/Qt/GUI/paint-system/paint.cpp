//
// Created by kaiser on 19-3-26.
//

#include "paint-system/paint.h"

#include <QApplication>

int main(int argc, char *argv[]) {
  QApplication app{argc, argv};

  Paint paint;
  paint.show();

  return QApplication::exec();
}