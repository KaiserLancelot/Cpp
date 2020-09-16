//
// Created by kaiser on 18-12-5.
//

#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::vector<std::string> vs{"1", "2", "3"};

  std::int32_t sum{};
  for (const auto& s : vs) {
    sum += std::stoi(s);
  }

  std::cout << sum << '\n';
}
