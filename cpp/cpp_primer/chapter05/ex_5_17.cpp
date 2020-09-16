//
// Created by kaiser on 18-11-27.
//

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

int main() {
  std::vector<std::int32_t> v1{0, 1, 1, 2}, v2{0, 1, 1, 2, 3, 5, 8};

  for (decltype(v1)::size_type index{};
       index < std::min(std::size(v1), std::size(v2)); ++index) {
    if (v1[index] != v2[index]) {
      std::cout << "false\n";
      return 0;
    }
  }
  std::cout << "true\n";
}
