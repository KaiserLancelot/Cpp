//
// Created by kaiser on 20-4-22.
//

#include <cstdint>
#include <iostream>

int main() {
  std::int32_t ia[3][4]{{0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}};
  using Int4 = std::int32_t[4];

  for (const Int4& item : ia) {
    for (std::int32_t i : item) {
      std::cout << i << " ";
    }
  }
  std::cout << '\n';

  for (std::int32_t i = 0; i < 3; ++i) {
    for (std::int32_t j = 0; j < 4; ++j) {
      std::cout << ia[i][j] << " ";
    }
  }
  std::cout << '\n';

  for (Int4* p{std::begin(ia)}; p != std::end(ia); ++p) {
    for (std::int32_t* q{std::begin(*p)}; q != std::end(*p); ++q) {
      std::cout << *q << ' ';
    }
  }
  std::cout << '\n';
}
