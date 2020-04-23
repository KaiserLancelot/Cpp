//
// Created by kaiser on 19-3-20.
//

#include "enum.h"

#include <QDebug>

int main() {
  qDebug() << ToString<Test::Value>(Test::kV2);
  qDebug() << ToEnum<Test::Value>("kV1");
}
