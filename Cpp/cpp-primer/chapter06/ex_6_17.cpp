//
// Created by kaiser on 18-11-28.
//

#include <cctype>
#include <iostream>
#include <string>

bool Fun1(const std::string &s) {
  for (auto element : s) {
    if (std::isupper(element)) {
      return true;
    }
  }
  return false;
}

void Fun2(std::string &s) {
  for (auto &element : s) {
    element = std::tolower(element);
  }
}

int main() {
  std::string s{"HELLO WORLD"};
  Fun2(s);
  std::cout << s << '\n';
  std::cout << std::boolalpha << Fun1(s) << '\n';
}
