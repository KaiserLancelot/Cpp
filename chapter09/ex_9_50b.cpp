//
// Created by kaiser on 18-12-5.
//

#include <vector>
#include <iostream>
#include <string>

int main() {
  std::vector<std::string> vs{"1.1", "2.2", "3.3"};

  double sum{};
  for (const auto &s:vs) {
    sum += std::stod(s);
  }

  std::cout << sum << '\n';
}