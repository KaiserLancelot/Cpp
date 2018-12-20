//
// Created by kaiser on 18-12-17.
//

#include <vector>
#include <iostream>
#include <list>
#include <cstdint>
#include <algorithm>
#include <iterator>

int main() {
  std::vector<std::int32_t> vi{1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::list<std::int32_t> li;

  std::reverse_copy(std::begin(vi) + 3, std::begin(vi) + 7, std::back_inserter(li));

  for (auto i:li) {
    std::cout << i << ' ';
  }
  std::cout << '\n';
}