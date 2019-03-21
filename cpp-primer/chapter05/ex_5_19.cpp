//
// Created by kaiser on 18-11-27.
//

#include <iostream>
#include <string>

int main() {
  do {
    std::string s1, s2;
    std::cout << "enter two string: ";
    if (std::cin >> s1 >> s2)
      std::cout << (std::size(s1) > std::size(s2) ? s2 : s1) << '\n';
  } while (std::cin);
}