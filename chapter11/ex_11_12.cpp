//
// Created by kaiser on 18-12-18.
//

#include <string>
#include <vector>
#include <cstdint>
#include <utility>
#include <iostream>

int main() {
  std::string s;
  std::int32_t i;
  std::vector<std::pair<std::string, std::int32_t >> v;

  while (std::cin >> s >> i) {
    v.emplace_back(s, i);
  }
}