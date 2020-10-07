#include <cstdint>
#include <iostream>
#include <unordered_map>

#include "sales_item.h"

int main() {
  SalesItem item;
  std::unordered_map<std::string, std::int32_t> data;

  while (std::cin >> item) {
    ++data[item.isbn()];
  }

  for (const auto& [isbn, cnt] : data) {
    std::cout << isbn << ' ' << cnt << '\n';
  }
}
