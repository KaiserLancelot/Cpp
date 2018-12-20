//
// Created by kaiser on 18-12-17.
//

#include <vector>
#include <list>
#include <algorithm>
#include <string>
#include <iterator>
#include <iostream>

int main() {
  std::vector<std::string> vs{"a", "a", "b", "a"};
  std::list<std::string> ls;

  std::sort(std::begin(vs), std::end(vs));
  std::unique_copy(std::begin(vs), std::end(vs), std::back_inserter(ls));

  for (const auto &s:ls) {
    std::cout << s << '\n';
  }
}