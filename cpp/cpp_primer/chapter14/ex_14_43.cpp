//
// Created by kaiser on 18-12-24.
//

#include <algorithm>
#include <cstdint>
#include <functional>
#include <iostream>
#include <vector>

int main() {
  std::vector<std::int32_t> vi{1, 2, 3, 4, 5};
  std::int32_t i{60};

  std::cout << std::boolalpha
            << std::all_of(std::begin(vi), std::end(vi), [i](auto ele) {
                 return std::modulus<>{}(i, ele) == 0;
               });
}
