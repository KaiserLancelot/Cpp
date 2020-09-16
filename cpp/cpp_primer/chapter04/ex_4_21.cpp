//
// Created by kaiser on 18-11-26.
//

#include <cstdint>
#include <iostream>
#include <vector>

int main() {
  std::vector<std::int32_t> vi{1, 2, 3, 4, 5};

  for (auto& element : vi) {
    element % 2 ? element *= 2 : element;
  }
  for (auto element : vi) {
    std::cout << element << ' ';
  }
  std::cout << '\n';
}
