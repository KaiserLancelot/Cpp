//
// Created by kaiser on 18-12-5.
//

#include <string>
#include <list>
#include <iostream>

int main() {
  std::string str;
  std::list<std::string> list;

  while (std::cin >> str) {
    list.push_back(str);
  }

  for (auto iter{std::cbegin(list)}; iter != std::cend(list); ++iter) {
    std::cout << *iter << '\n';
  }
}