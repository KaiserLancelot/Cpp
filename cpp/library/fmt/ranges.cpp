//
// Created by kaiser on 2020/4/27.
//

#include <cstdint>
#include <tuple>
#include <vector>

#include <fmt/ranges.h>

int main() {
  std::tuple<char, std::int32_t, float> t{'a', 1, 2.0F};
  fmt::print("{}", t);

  std::tuple<std::int32_t, char> tt = {1, 'a'};
  fmt::print("{}", fmt::join(tt, ", "));

  std::vector<std::int32_t> v{1, 2, 3};
  fmt::print("{}\n", v);
}
