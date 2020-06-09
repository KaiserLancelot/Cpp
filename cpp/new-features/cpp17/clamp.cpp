//
// Created by kaiser on 19-3-21.
//

#include <algorithm>
#include <iostream>
#include <random>

int main() {
  std::default_random_engine e{std::random_device{}()};
  std::uniform_int_distribution<> u{-10, 10};
  for (std::int32_t i{0}; i < 10; ++i) {
    // C++17 std::clamp
    // 若 v 小于 lo, 则返回 lo;若 v 大于 hi,
    // 则返回 hi;否则返回 v.使用 operator< 比较值
    std::cout << std::clamp(u(e), -5, 5) << '\n';
  }
}