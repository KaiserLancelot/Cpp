//
// Created by kaiser on 18-12-5.
//

#include <cstdint>
#include <iostream>
#include <vector>

bool find(std::vector<std::int32_t>::const_iterator begin,
          std::vector<std::int32_t>::const_iterator end, std::int32_t value) {
  for (; begin != end; ++begin) {
    if (*begin == value) {
      return true;
    }
  }
  return false;
}

int main() {
  std::vector<std::int32_t> vi{1, 2, 3};
  std::cout << std::boolalpha << find(std::cbegin(vi), std::cend(vi), 2);
}
