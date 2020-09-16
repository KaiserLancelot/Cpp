//
// Created by kaiser on 18-12-5.
//

#include <cstdint>
#include <forward_list>
#include <iostream>

int main() {
  std::forward_list<std::int32_t> data{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  for (auto cur{std::begin(data)}, prv{data.before_begin()};
       cur != std::end(data);) {
    if (*cur % 2) {
      data.insert_after(prv, *cur);
      prv = cur;
      ++cur;
    } else {
      cur = data.erase_after(prv);
    }
  }

  for (auto i : data) {
    std::cout << i << " ";
  }
}
