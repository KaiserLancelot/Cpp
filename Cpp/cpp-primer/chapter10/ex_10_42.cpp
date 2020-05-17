//
// Created by kaiser on 18-12-17.
//

#include <algorithm>
#include <iostream>
#include <list>
#include <string>

void ElimDups(std::list<std::string> &words) {
  words.sort();
  words.unique();
}

int main() {
  std::list<std::string> vs{"a", "a", "c", "c", "b"};
  ElimDups(vs);
  for (const auto &s : vs) {
    std::cout << s << '\n';
  }
}
