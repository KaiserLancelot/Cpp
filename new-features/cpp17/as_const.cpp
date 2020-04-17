//
// Created by kaiser on 2020/4/18.
//

#include <iostream>
#include <string>
#include <utility>

int main() {
  // 当基于范围的 for 循环被用于一个具有写时复制语义的（非
  // const）对象时, 它可能会通过(隐式)调用非 const 的 begin()
  // 成员函数触发深层复制
  // 如果想要避免这种行为(比如循环实际上不会修改这个对象), 可以使用
  // std::as_const

  // 假设是写时复制的字符串
  std::string cow_string{"str"};

  // for(auto x : str) { /* ... */ } // 可能会导致深层复制

  for (auto c : std::as_const(cow_string)) {
    std::cout << c;
  }
  std::cout << '\n';
}
