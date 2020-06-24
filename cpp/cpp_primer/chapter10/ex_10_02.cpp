//
// Created by kaiser on 18-12-17.
//

#include <algorithm>
#include <iostream>
#include <list>
#include <string>

int main() {
  std::list<std::string> ls{"a", "b", "b"};
  std::cout << std::count(std::cbegin(ls), std::cend(ls), "b") << '\n';
}
