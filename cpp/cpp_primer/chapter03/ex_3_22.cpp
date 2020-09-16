//
// Created by kaiser on 18-11-22.
//

#include <cctype>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::vector<std::string> text;

  for (auto it{std::begin(text)}; it != std::end(text) && !std::empty(*it);
       ++it) {
    for (auto&& c : *it) {
      if (std::isalpha(c)) {
        c = static_cast<char>(std::toupper(c));
      }
    }
    std::cout << *it << ' ';
  }
}
