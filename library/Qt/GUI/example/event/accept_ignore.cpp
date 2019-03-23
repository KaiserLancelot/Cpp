//
// Created by kaiser on 19-3-23.
//

#include "accept_ignore.h"

#include <QApplication>

int main(int argc, char *argv[]) {
  QApplication app{argc, argv};

  CustomButton button;
  button.setText("This is button!");
  button.setMinimumSize(200, 200);
  button.show();

  QApplication::exec();
}