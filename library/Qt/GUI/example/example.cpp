//
// Created by kaiser on 19-3-23.
//

#include <QApplication>
#include <QMainWindow>

int main(int argc, char *argv[]) {
  QApplication app{argc, argv};

  QMainWindow window;
  window.show();

  return QApplication::exec();
}