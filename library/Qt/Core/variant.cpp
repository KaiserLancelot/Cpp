//
// Created by kaiser on 19-4-14.
//

#include <iostream>

#include <QVariant>

// QVariant 类似与 std::variant
// 它的 operator== 将使用它保存的元素的类型的 operator== 进行比较
// 如果两个运算对象的类型不同, 将尝试进行转换
int main() {
  QVariant v{123};
  std::cout << v.toInt() << '\n';
  // 可以转换, 为 "123"
  std::cout << v.toString().toStdString() << '\n';

  v = QVariant{"你好"};
  // 不能转换为 int, 为 0
  std::cout << v.toInt() << '\n';
  std::cout << v.toString().toStdString() << '\n';
}
