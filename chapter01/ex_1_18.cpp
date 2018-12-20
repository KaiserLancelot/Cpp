//
// Created by kaiser on 18-11-20.
//

#include <cstdint>
#include <iostream>

int main() {
  std::int32_t currVal{}, val{};

  if (std::cin >> currVal) {
    std::int32_t cnt{1};
    while (std::cin >> val) {
      if (val == currVal)
        ++cnt;
      else {
        std::cout << currVal << " occurs "
                  << cnt << " times\n";
        cnt = 1;
        currVal = val;
      }
    }
    std::cout << currVal << " occurs "
              << cnt << " times\n";
  }
}