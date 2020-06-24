//
// Created by kaiser on 19-3-6.
//

#include <iostream>

template <typename T> std::ostream &print(std::ostream &os, const T &t) {
  return os << t;
}

template <typename T, typename... Args>
std::ostream &print(std::ostream &os, const T &t, const Args &... rest) {
  os << t << ", ";
  return print(os, rest...);
}

int main() {
  print(std::cout, 1) << '\n';
  print(std::cout, 1, 2) << '\n';
  print(std::cout, 1, 2, 3, 4, "sss", 42.4242) << '\n';
}
