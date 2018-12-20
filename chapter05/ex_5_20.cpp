//
// Created by kaiser on 18-11-27.
//

#include <iostream>
#include <string>

int main() {
  std::string curr, pre;

  while (std::cin >> curr) {
    if (curr == pre)
      break;
    pre = curr;
  }

  if (std::cin.eof())
    std::cout << "No consecutively repeated strings\n";
  else
    std::cout << curr << '\n';
}