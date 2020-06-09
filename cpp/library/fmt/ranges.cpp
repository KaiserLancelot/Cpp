//
// Created by kaiser on 2020/4/27.
//

#include <fmt/ranges.h>

int main() {
  std::tuple<char, int, float> t{'a', 1, 2.0F};
  // Prints "('a', 1, 2.0)"
  fmt::print("{}", t);

  std::tuple<int, char> tt = {1, 'a'};
  // Prints "1, a"
  fmt::print("{}", fmt::join(tt, ", "));
}
