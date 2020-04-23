//
// Created by kaiser on 18-12-18.
//

#include <cstdint>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

int main() {
  std::string s;
  std::int32_t i;
  std::vector<std::pair<std::string, std::int32_t>> v;

  while (std::cin >> s >> i) {
    v.emplace_back(s, i);
    // v.push_back({s, i});
    // v.push_back(std::make_pair(s, i));
  }
}