//
// Created by kaiser on 19-3-11.
//

#include <iostream>
#include <regex>
#include <string>

int main() {
  std::regex error_pattern{"[[:alpha:]]*[^c]ei[[:alpha:]]*", std::regex::icase};
  std::string words("receipt freind theif receive");

  for (std::sregex_iterator
           iter{std::begin(words), std::end(words), error_pattern},
       end;
       iter != end; ++iter) {
    std::cout << iter->str() << '\n';
  }
}