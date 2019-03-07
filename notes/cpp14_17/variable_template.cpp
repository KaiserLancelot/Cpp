//
// Created by kaiser on 19-3-8.
//

#include <cstdint>
#include <iostream>

// C++14 变量模板
template <typename T>
constexpr T pi(3.1415926);

int main() {
  std::cout << pi<std::int32_t> << '\n';
  std::cout << pi<double> << '\n';
}