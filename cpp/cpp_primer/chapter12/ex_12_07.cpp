//
// Created by kaiser on 18-12-19.
//

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <memory>
#include <vector>

std::shared_ptr<std::vector<std::int32_t>> make_vec() {
  return std::make_shared<std::vector<std::int32_t>>();
}

void read_vec(const std::shared_ptr<std::vector<std::int32_t>>& vec) {
  vec->assign(std::istream_iterator<std::int32_t>{std::cin}, {});
}

void print_vec(const std::shared_ptr<std::vector<std::int32_t>>& vec) {
  std::copy(std::begin(*vec), std::end(*vec),
            std::ostream_iterator<std::int32_t>{std::cout, " "});
}

int main() {
  auto vec{make_vec()};
  read_vec(vec);
  print_vec(vec);
  std::cout << '\n';
}
