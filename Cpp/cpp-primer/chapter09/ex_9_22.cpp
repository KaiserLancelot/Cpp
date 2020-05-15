/**
 * @ Author: KaiserLancelot
 * @ Create Time: 2020-05-16 05:15:29
 * @ Modified time: 2020-05-16 05:32:38
 */

#include <cstdint>
#include <iostream>
#include <vector>

int main() {
  std::vector<std::int32_t> v{1, 2, 3, 3, 5, 6, 7, 8, 9};
  std::int32_t some_value{3};

  auto mid{[&v] { return std::begin(v) + std::size(v) / 2; }};
  // 这里使用 begin != mid() 会出错
  for (auto begin{std::begin(v)}; begin < mid(); ++begin) {
    if (*begin == some_value) {
      begin = v.insert(begin, some_value * 2);
      ++begin;
    }
  }

  for (auto item : v) {
    std::cout << item << ' ';
  }
  std::cout << '\n';
}
