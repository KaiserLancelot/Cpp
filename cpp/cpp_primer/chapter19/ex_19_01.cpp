//
// Created by kaiser on 19-3-15.
//

#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <string>

void* operator new(std::size_t size) {
  if (void* mem{std::malloc(size)}) {
    return mem;
  } else {
    throw std::bad_alloc{};
  }
}

void operator delete(void* mem) noexcept { std::free(mem); }

int main() {
  auto p{new std::string("kaiser")};
  std::cout << *p << '\n';
  delete p;
}
