/**
 * @ Author: KaiserLancelot
 * @ Create Time: 2020-05-16 05:58:42
 * @ Modified time: 2020-05-16 06:02:51
 */

#include <cstdint>
#include <iostream>
#include <vector>

int main() {
  std::vector<std::int32_t> v{1, 2, 3, 4, 5};

  auto iter{std::begin(v)};
  while (iter != std::end(v)) {
    if (*iter % 2) {
      iter = v.insert(iter, *iter);
      // ++iter;
    }
    ++iter;
  }

  for (auto i : v) {
    std::cout << i << ' ';
  }
  std::cout << '\n';
}
