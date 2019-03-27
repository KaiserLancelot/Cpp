//
// Created by kaiser on 19-3-26.
//

#include "summary.h"

#include <QApplication>

int main(int argc, char *argv[]) {
  QApplication app{argc, argv};

  Label label;
  EventFilter filter{&label, &label};
  app.installEventFilter(&filter);
  label.show();

  return QApplication::exec();
}