//
// Created by kaiser on 20-4-22.
//

#include <cstdint>
#include <iostream>
#include <vector>

int main() {
  std::int32_t arr[] = {1, 2, 3};
  std::vector<std::int32_t> v{std::begin(arr), std::end(arr)};

  for (const auto &item : v) {
    std::cout << item << ' ';
  }

  std::cout << '\n';
}
