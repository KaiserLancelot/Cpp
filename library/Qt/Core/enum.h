
//
// Created by kaiser on 19-3-20.
//

#ifndef CPP_PRIMER_ENUM_H
#define CPP_PRIMER_ENUM_H

#include <QMetaEnum>
#include <QObject>
#include <string>

class Enum : public QObject {
  Q_OBJECT
 public:
  enum Values { kTest };
  Q_ENUM(Values);
};

class Enum2 : public QObject {
  Q_OBJECT
 public:
  enum Values { kTest2 };
  Q_ENUM(Values);
};

template <typename T>
std::string ToString(T value) {
  return QMetaEnum::fromType<T>().valueToKey(value) + 1;
}

#endif  // CPP_PRIMER_ENUM_H