//
// Created by kaiser on 19-3-12.
//

#include <iostream>
#include <random>

unsigned long Fun() {
  static std::default_random_engine e;
  return e();
}

unsigned long Fun(unsigned long seed) {
  static std::default_random_engine e{seed};
  return e();
}

unsigned long Fun(unsigned long seed, unsigned long min, unsigned long max) {
  static std::default_random_engine e{seed};
  static std::uniform_int_distribution<unsigned long> u{min, max};
  return u(e);
}

int main() {
  for (std::int32_t i{0}; i < 10; ++i) {
    std::cout << Fun(std::random_device{}(), 0, 20) << ' ';
  }
  std::cout << '\n';
}
