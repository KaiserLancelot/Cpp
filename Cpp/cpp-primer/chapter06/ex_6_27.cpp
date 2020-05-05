//
// Created by kaiser on 18-11-28.
//

#include <cstdint>
#include <initializer_list>
#include <iostream>

std::int32_t Sum(std::initializer_list<std::int32_t> il) {
  std::int32_t sum{0};
  for (auto element : il) {
    sum += element;
  }
  return sum;
}

int main() { std::cout << Sum({2, 2, 3, 4}) << '\n'; }
