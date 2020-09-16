//
// Created by kaiser on 18-12-17.
//

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::int32_t biger_than_six(const std::vector<std::string>& vs) {
  return std::count_if(std::begin(vs), std::end(vs),
                       [](const auto& s) { return std::size(s) > 6; });
}

int main() {
  std::vector<std::string> vs{"aaaaaaaa", "aaaaaaaaaa", "aaa"};
  std::cout << biger_than_six(vs) << '\n';
}
