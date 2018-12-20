//
// Created by kaiser on 18-11-28.
//

#include <cstdint>
#include <iostream>

void fun(void *) {
  std::cout << "fun(void*)\n";
}

void fun(bool) {
  std::cout << "fun(bool)\n";
}

int main() {
  std::int32_t *p{nullptr};
  fun(p); // fun(void*)
}