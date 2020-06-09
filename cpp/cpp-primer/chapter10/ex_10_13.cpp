//
// Created by kaiser on 18-12-17.
//

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

bool predicate(const std::string &s) { return std::size(s) >= 5; }

int main() {
  std::vector<std::string> vs{"a",         "as",        "aasss",
                              "aaaaassaa", "aaaaaabba", "aaa"};
  auto end{std::partition(std::begin(vs), std::end(vs), predicate)};

  for (auto begin{std::begin(vs)}; begin != end; ++begin) {
    std::cout << *begin << '\n';
  }
}
