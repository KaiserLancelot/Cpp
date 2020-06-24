//
// Created by kaiser on 18-11-28.
//

#include <cstdint>
#include <iostream>

void f() { std::cout << "F()\n"; }

void f(std::int32_t) { std::cout << "F(std::int32_t)\n"; }

void f(std::int32_t, std::int32_t) {
  std::cout << "F(std::int32_t, std::int32_t)\n";
}

void f(double, double) { std::cout << "F(double, double)\n"; }

void f(void *) { std::cout << "F(void *)\n"; }

void f(bool) { std::cout << "F(bool)\n"; }

int main() {
  // f(2.56, 42); // error
  f(42);
  f(42, 0);
  f(2.56, 3.14);

  std::int32_t *p{};

  f(p); // F(void *)
}
