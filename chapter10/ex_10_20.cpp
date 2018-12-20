//
// Created by kaiser on 18-12-17.
//

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

std::int32_t BigerThanSix(const std::vector<std::string> &vs) {
  return std::count_if(std::begin(vs), std::end(vs),
                       [](const auto &s) { return std::size(s) > 6; });
}

int main() {
  std::vector<std::string> vs{"aaaaaaaa", "aaaaaaaaaa", "aaa"};
  std::cout << BigerThanSix(vs) << '\n';
}