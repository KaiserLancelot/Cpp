//
// Created by kaiser on 18-11-28.
//

#include <cstdint>
#include <iostream>

int main(int argc, char *argv[]) {
  for (std::int32_t i{1}; i != argc; ++i) {
    std::cout << argv[i] << '\n';
  }
}
