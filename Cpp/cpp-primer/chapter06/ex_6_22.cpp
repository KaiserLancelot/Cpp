//
// Created by kaiser on 20-5-5.
//

#include <cstdint>
#include <iostream>

void Swap(std::int32_t *&lhs, std::int32_t *&rhs) {
  auto temp{lhs};
  lhs = rhs;
  rhs = temp;
}

int main() {
  std::int32_t a{10}, b{42};
  auto pa{&a}, pb{&b};
  std::cout << pa << ' ' << pb << '\n';

  Swap(pa, pb);
  std::cout << pa << ' ' << pb << '\n';
}
