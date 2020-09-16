//
// Created by kaiser on 20-4-22.
//

#include <cstddef>
#include <cstdint>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
  // a
  std::int32_t arr[10];
  std::iota(std::begin(arr), std::end(arr), 0);

  std::int32_t arr2[10];
  for (std::size_t i = 0; i < 10; ++i) {
    arr2[i] = arr[i];
  }
  for (const auto& item : arr2) {
    std::cout << item << ' ';
  }
  std::cout << '\n';

  // b
  std::vector<std::int32_t> v(10);
  std::iota(std::begin(v), std::end(v), 0);

  std::vector<std::int32_t> v2{v};
  for (const auto& item : v2) {
    std::cout << item << ' ';
  }
  std::cout << '\n';
}
