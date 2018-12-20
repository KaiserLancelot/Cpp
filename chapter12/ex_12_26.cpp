//
// Created by kaiser on 18-12-19.
//

#include <string>
#include <iostream>
#include <memory>
#include <iterator>
#include <cstddef>

int main() {
  constexpr std::size_t size{10};
  std::allocator<std::string> alloc;

  const auto p{alloc.allocate(size)};
  std::uninitialized_copy_n(std::istream_iterator < std::string > {std::cin}, size, p);
  std::destroy_n(p, size);
  alloc.deallocate(p, size);
}