//
// Created by kaiser on 19-4-15.
//

#include <cstdlib>

#include <QApplication>

#include "login.h"
#include "main_window.h"

int main(int argc, char *argv[]) {
  QApplication app{argc, argv};

  Login login;
  if (login.exec() == QDialog::Accepted) {
    MainWindow window;
    window.show();
    return QApplication::exec();
  } else {
    QApplication::exit(EXIT_SUCCESS);
  }
}
