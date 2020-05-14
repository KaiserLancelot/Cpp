/**
 * @ Author: KaiserLancelot
 * @ Create Time: 2020-05-15 03:38:50
 * @ Modified time: 2020-05-15 03:43:14
 */

// TODO learn

#include <iostream>
#include <ranges>
#include <vector>

int main() {
  std::vector<int> ints{0, 1, 2, 3, 4, 5};
  auto even = [](int i) { return 0 == i % 2; };
  auto square = [](int i) { return i * i; };

  for (int i :
       ints | std::views::filter(even) | std::views::transform(square)) {
    std::cout << i << ' ';
  }
}
