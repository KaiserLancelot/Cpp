//
// Created by kaiser on 18-11-22.
//

#include <iostream>
#include <string>

int main() {
  //a
  std::string line;
  while (std::getline(std::cin, line))
    std::cout << line << '\n';

  //b
  std::string word;
  while (std::cin >> word)
    std::cout << word << '\n';
}