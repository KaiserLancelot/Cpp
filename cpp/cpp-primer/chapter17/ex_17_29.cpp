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

int main() {
  for (std::int32_t i{0}; i < 10; ++i) {
    std::cout << Fun(std::random_device{}()) << ' ';
  }
  std::cout << '\n';
}