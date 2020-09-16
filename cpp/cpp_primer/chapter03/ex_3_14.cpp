//
// Created by kaiser on 18-11-22.
//

#include <cstdint>
#include <iostream>
#include <vector>

int main() {
  std::vector<std::int32_t> vi;
  std::int32_t value;

  while (std::cin >> value) {
    vi.push_back(value);
  }
}
