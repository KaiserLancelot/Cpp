//
// Created by kaiser on 18-12-17.
//

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

bool is_shorter(const std::string &s1, const std::string &s2) {
  return std::size(s1) < std::size(s2);
}

void elim_dups(std::vector<std::string> &words) {
  std::sort(std::begin(words), std::end(words));
  words.erase(std::unique(std::begin(words), std::end(words)), std::end(words));
}

int main() {
  std::vector<std::string> vs{"aaaaa", "aaaaa", "cc", "cc", "b"};
  elim_dups(vs);
  std::stable_sort(std::begin(vs), std::end(vs), is_shorter);
  for (const auto &s : vs) {
    std::cout << s << '\n';
  }
}
