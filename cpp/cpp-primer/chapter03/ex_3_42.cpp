//
// Created by kaiser on 20-4-22.
//

#include <cstdint>
#include <iostream>
#include <vector>

int main() {
  std::vector<std::int32_t> v{1, 2, 3};
  std::int32_t arr[3];

  for (std::size_t i = 0; i < 3; ++i) {
    arr[i] = v[i];
  }

  for (const auto &item : arr) {
    std::cout << item << " ";
  }
  std::cout << '\n';
}
