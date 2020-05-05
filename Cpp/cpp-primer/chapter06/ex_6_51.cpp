//
// Created by kaiser on 18-11-28.
//

#include <cstdint>
#include <iostream>

void F() { std::cout << "F()\n"; }

void F(std::int32_t) { std::cout << "F(std::int32_t)\n"; }

void F(std::int32_t, std::int32_t) {
  std::cout << "F(std::int32_t, std::int32_t)\n";
}

void F(double, double) { std::cout << "F(double, double)\n"; }

void F(void *) { std::cout << "F(void *)\n"; }

void F(bool) { std::cout << "F(bool)\n"; }

int main() {
  // f(2.56, 42); // error
  F(42);
  F(42, 0);
  F(2.56, 3.14);

  std::int32_t *p{};

  F(p);  // F(void *)
}
