//
// Created by kaiser on 18-11-28.
//

#include <cstdint>
#include <iostream>

void Swap(std::int32_t &p1, std::int32_t &p2) {
  auto temp{p1};
  p1 = p2;
  p2 = temp;
}

int main() {
  std::int32_t a{10}, b{20};
  std::cout << a << ' ' << b << '\n';
  
  Swap(a, b);
  std::cout << a << ' ' << b << '\n';
}
