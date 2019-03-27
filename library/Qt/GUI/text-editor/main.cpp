//
// Created by kaiser on 19-3-26.
//

#include <QApplication>

#include "main_window.h"

int main(int argc, char *argv[]) {
  QApplication app{argc, argv};
  // 设置图标
  QApplication::setWindowIcon(QIcon{":/images/icon.png"});
  QApplication::setApplicationName("Text Editor");

  MainWindow window;
  window.show();

  return QApplication::exec();
}