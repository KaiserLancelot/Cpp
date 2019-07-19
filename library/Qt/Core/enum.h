
//
// Created by kaiser on 19-3-20.
//

#ifndef CPP_PRIMER_ENUM_H
#define CPP_PRIMER_ENUM_H

#include <QMetaEnum>
#include <QObject>
#include <QString>

class Test : public QObject {
  Q_OBJECT
 public:
  enum Value { kV1, kV2 };
  Q_ENUM(Value)
};

template <typename T>
QString ToString(qint32 enum_key) {
  return QMetaEnum::fromType<T>().valueToKey(enum_key);
}

template <typename T>
int ToEnum(const QString &enum_str) {
  return QMetaEnum::fromType<T>().keyToValue(enum_str.toLocal8Bit().data());
}

#endif  // CPP_PRIMER_ENUM_H
