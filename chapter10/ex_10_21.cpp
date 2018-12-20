//
// Created by kaiser on 18-12-17.
//

#include <iostream>
#include <cstdint>

int main() {
  std::int32_t i{10};
  auto f{[&i]()mutable {
    if (i > 0) {
      --i;
    }
    return i == 0;
  }};

  while (!f()) {
    std::cout << i << '\n';
  }
}