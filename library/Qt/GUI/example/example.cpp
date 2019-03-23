//
// Created by kaiser on 19-3-23.
//

#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[]) {
  QApplication app{argc, argv};

  {
    // QWidget window;
    // QPushButton quit("Quit", &window);
    QPushButton quit("Quit");
    QWidget window;

    quit.setParent(&window);
  }

  // return QApplication::exec();
}