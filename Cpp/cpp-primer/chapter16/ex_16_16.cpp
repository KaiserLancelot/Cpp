//
// Created by kaiser on 19-3-3.
//

#include <cstdint>
#include <iostream>
#include <vector>

#include "ex_16_16.h"

int main() {
  Vec<std::int32_t> v{1, 2, 3, 4, 5};
  Vec<std::int32_t> v2;

  v2 = v;
  std::cout << v2.Capacity() << '\n';
  v2.PushBack(99);
  v2.Resize(2, 2);

  for (auto t : v2) {
    std::cout << t << ' ';
  }

  std::cout << v2.Capacity() << '\n';

  //  std::vector<std::int32_t> v{1, 2, 3, 4, 5};
  //  std::vector<std::int32_t> v2;
  //
  //  v2 = v;
  //  std::cout << v2.capacity() << '\n';
  //  v2.push_back(99);
  //  v2.resize(2, 2);
  //
  //  for (auto t : v2) {
  //    std::cout << t << ' ';
  //  }
  //
  //  std::cout << v2.capacity() << '\n';
}
