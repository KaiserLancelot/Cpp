//
// Created by kaiser on 2020/1/7.
//

#include <cstdint>
#include <iostream>
#include <vector>

#include <range/v3/numeric.hpp>
#include <range/v3/view.hpp>

int main() {
  std::vector<std::int32_t> vi{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  // [2,4,6,8,10]
  auto range{vi |
             ranges::views::filter([](std::int32_t i) { return i % 2 == 0; }) |
             ranges::views::transform(
                 [](std::int32_t i) { return std::to_string(i); })};
  std::cout << range << '\n';

  // 5
  auto sum{ranges::accumulate(
      ranges::views::ints(1, ranges::unreachable) |
          ranges::views::transform([](std::int32_t i) { return i * i; }) |
          ranges::views::take(2),
      0)};
  std::cout << sum << '\n';
}
