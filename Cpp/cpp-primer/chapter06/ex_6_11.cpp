//
// Created by kaiser on 18-11-28.
//

#include <cstdint>
#include <iostream>

void Reset(std::int32_t &i) { i = 0; }

int main() {
  std::int32_t i{10};
  std::cout << i << '\n';
  
  Reset(i);
  std::cout << i << '\n';
}
