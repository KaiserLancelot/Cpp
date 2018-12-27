//
// Created by kaiser on 18-12-17.
//

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

int main() {
  std::vector<std::int32_t> vi(10, -1);
  std::fill_n(std::begin(vi), 10, 0);
  for (auto i : vi) {
    std::cout << i << ' ';
  }
  std::cout << '\n';
}