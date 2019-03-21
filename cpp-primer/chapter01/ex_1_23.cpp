//
// Created by kaiser on 18-11-20.
//

#include <cstdint>
#include <iostream>
#include <unordered_map>
#include "Sales_item.h"

int main() {
  Sales_item item;
  std::unordered_map<std::string, std::int32_t> data;

  while (std::cin >> item) {
    ++data[item.isbn()];
  }

  for (const auto& [isbn, cnt] : data) std::cout << isbn << ' ' << cnt << '\n';
}