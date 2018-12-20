//
// Created by kaiser on 18-12-5.
//

#include <string>
#include <deque>
#include <iostream>

int main() {
  std::string str;
  std::deque<std::string> deque;

  while (std::cin >> str) {
    deque.push_back(str);
  }

  for (auto iter{std::cbegin(deque)}; iter != std::cend(deque); ++iter) {
    std::cout << *iter << '\n';
  }
}