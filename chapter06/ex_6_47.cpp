//
// Created by kaiser on 18-11-28.
//

#include <iostream>
#include <cstdint>
#include <vector>

void PrintVector(std::vector<std::int32_t>::const_iterator begin,
                 std::vector<std::int32_t>::const_iterator end) {
  if (begin != end) {
    std::cout << *begin++ << '\n';
#ifndef NDEBUG
    std::cout << "size: " << ' ' << end - begin << '\n';
#endif
    PrintVector(begin, end);
  }
}

int main() {
  std::vector<std::int32_t> vi{1, 2, 3};
  PrintVector(std::begin(vi), std::end(vi));
}