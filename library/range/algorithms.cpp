//
// Created by kaiser on 2020/1/7.
//

#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

#include <range/v3/algorithm.hpp>

int main() {
  std::string s{"hello"};
  ranges::for_each(s, [](char ch) { std::cout << ch << ' '; });
  std::cout << '\n';

  std::vector<std::int32_t> v{6, 2, 3, 4, 5, 6};
  std::cout << std::boolalpha
            << ranges::any_of(v, [](std::int32_t i) { return i == 6; }) << '\n';
}
