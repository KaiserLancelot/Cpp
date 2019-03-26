//
// Created by kaiser on 19-3-26.
//

#include <QApplication>
#include <QCommandLineParser>

#include "main_window.h"

int main(int argc, char *argv[]) {
  QApplication app{argc, argv};
  QApplication::setApplicationName("text editor");
  QApplication::setApplicationVersion("1.0");

  QCommandLineParser parser;
  parser.addHelpOption();
  parser.addVersionOption();

  MainWindow window;
  window.show();

  return QApplication::exec();
}