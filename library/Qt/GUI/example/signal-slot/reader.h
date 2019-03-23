//
// Created by kaiser on 19-3-23.
//

#ifndef CPP_READER_H
#define CPP_READER_H

#include <QObject>
#include <iostream>
#include <string>

class Reader : public QObject {
  Q_OBJECT
 public:
  void ReceiveNewspaper(const std::string &name) {
    std::cout << "Receive newspaper: " << name << '\n';
  }
};

#endif  // CPP_READER_H