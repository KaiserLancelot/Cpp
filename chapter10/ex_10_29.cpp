//
// Created by kaiser on 18-12-17.
//

#include <vector>
#include <string>
#include <iterator>
#include <fstream>
#include <iostream>

int main() {
  std::ifstream ifs{"str"};
  std::vector<std::string> vs(std::istream_iterator < std::string > {ifs}, {});

  for (const auto &s:vs) {
    std::cout << s << '\n';
  }
}