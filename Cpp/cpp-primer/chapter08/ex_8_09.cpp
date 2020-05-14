//
// Created by kaiser on 18-12-3.
//

#include <iostream>
#include <sstream>
#include <string>

std::istream &Fun(std::istream &is) {
  std::string word;
  while (is >> word) {
    std::cout << word << '\n';
  }
  is.clear();
  return is;
}

int main() {
  std::istringstream iss{"Hello World"};
  Fun(iss);
}
