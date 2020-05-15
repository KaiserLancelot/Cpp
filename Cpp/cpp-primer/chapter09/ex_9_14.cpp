//
// Created by kaiser on 18-12-5.
//

#include <iostream>
#include <list>
#include <string>
#include <vector>

int main() {
  std::list<const char *> list{"a", "bb", "ccc"};
  std::vector<std::string> vs;
  vs.assign(std::cbegin(list), std::cend(list));

  for (const auto &ele : vs) {
    std::cout << ele << '\n';
  }
}
