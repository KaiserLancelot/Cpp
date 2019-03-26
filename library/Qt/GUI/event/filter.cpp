//
// Created by kaiser on 19-3-26.
//

#include "filter.h"

#include <QApplication>

int main(int argc, char *argv[]) {
  QApplication app{argc, argv};

  MainWindow window;
  window.setMinimumSize(600, 400);
  window.show();

  return QApplication::exec();
}