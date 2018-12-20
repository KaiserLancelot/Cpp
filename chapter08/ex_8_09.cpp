//
// Created by kaiser on 18-12-3.
//

#include <iostream>
#include <string>
#include <sstream>

std::istream &fun(std::istream &is) {
  std::string word;
  while (is >> word)
    std::cout << word << '\n';
  is.clear();
  return is;
}

int main() {
  std::istringstream iss{"Hello World"};
  fun(iss);
}