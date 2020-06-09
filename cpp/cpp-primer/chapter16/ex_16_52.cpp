//
// Created by kaiser on 19-3-6.
//

#include <iostream>
#include <string>

template <typename T, typename... Args>
void foo(const T &, const Args &... rest) {
  std::cout << sizeof...(Args) << '\n';
  std::cout << sizeof...(rest) << '\n';
}

int main() {
  int i = 0;
  double d = 3.14;
  std::string s("how now brown cow");

  foo(i, s, 42, d);
  foo(s, 42, "hi");
  foo(d, s);
  foo("hi");
}