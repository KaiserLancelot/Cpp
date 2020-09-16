//
// Created by kaiser on 20-4-22.
//

#include <cstddef>
#include <cstdint>
#include <iostream>
#include <numeric>

int main() {
  std::int32_t arr[10];
  std::iota(std::begin(arr), std::end(arr), 0);

  for (const auto& item : arr) {
    std::cout << item << ' ';
  }
  std::cout << '\n';
}
