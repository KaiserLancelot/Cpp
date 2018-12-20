//
// Created by kaiser on 18-11-22.
//

#include <iostream>
#include <string>
#include <cctype>

int main() {
  std::string s;
  std::getline(std::cin, s);

  for (auto element : s) {
    if (!std::ispunct(element))
      std::cout << element;
  }
  std::cout << '\n';
}