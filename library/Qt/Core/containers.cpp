//
// Created by kaiser on 19-4-9.
//

#include <iostream>

#include <QHash>
#include <QList>
#include <QString>

int main() {
  QList<QString> list;
  list << "a"
       << "b"
       << "c";

  for (const auto &item : list) {
    std::cout << item.toStdString() << '\n';
  }

  QHash<QString, QString> hash;
  hash.insert("a", "aa");
  hash.insert("b", "bb");

  // 这里得到的是 value , 想得到 key-value 需要使用迭代器
  for (const auto &item : hash) {
    std::cout << item.toStdString() << '\n';
  }
}
