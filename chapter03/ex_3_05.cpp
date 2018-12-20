//
// Created by kaiser on 18-11-22.
//

#include <iostream>
#include <string>

int main() {
  std::string total, s;

  //a
  while (std::cin >> s)
    total += s;
  std::cout << total << '\n';

  //b
  total.clear();
  while (std::cin >> s)
    total += ' ' + s;
  std::cout << total << '\n';
}