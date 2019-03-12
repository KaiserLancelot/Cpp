//
// Created by kaiser on 19-3-12.
//

#include <iostream>
#include <regex>
#include <string>

int main() {
  std::regex r{R"((\d{5})([-]?)(\d{4}))"};
  std::string s;
  std::smatch result;

  while (std::cin >> s) {
    if (std::regex_match(s, result, r)) {
      std::cout << "ok\n";
      std::cout << result.format("$1-$3") << '\n';
    } else {
      std::cout << "not ok\n";
    }
  }
}