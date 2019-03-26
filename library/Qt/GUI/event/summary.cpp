//
// Created by kaiser on 19-3-26.
//

#include "summary.h"

#include <QApplication>

int main(int argc, char *argv[]) {
  QApplication app{argc, argv};
  Label label;
  app.installEventFilter(new EventFilter{&label, &label});
  label.show();
  return QApplication::exec();
}