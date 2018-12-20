//
// Created by kaiser on 18-12-17.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void ElimDups(std::vector<std::string> &words) {
  std::sort(std::begin(words), std::end(words));
  words.erase(std::unique(std::begin(words), std::end(words)), std::end(words));
}

int main() {
  std::vector<std::string> vs{"a", "a", "c", "c", "b"};
  ElimDups(vs);
  for (const auto &s:vs) {
    std::cout << s << '\n';
  }
}