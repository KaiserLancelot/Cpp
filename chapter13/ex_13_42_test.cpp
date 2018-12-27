//
// Created by kaiser on 18-12-21.
//

#include "ex_13_42.h"

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

void RunQueries(std::ifstream &input) {
  TextQuery tq{input};
  while (true) {
    std::cout << "enter word to look for, or q to quit: ";
    std::string s;
    if (!(std::cin >> s) || s == "q") {
      break;
    }
    Print(std::cout, tq.Query(s)) << '\n';
  }
}

int main() {
  std::ifstream ifs{"story"};
  if (!ifs) {
    std::cerr << "can not open file\n";
    std::exit(EXIT_FAILURE);
  }

  RunQueries(ifs);
}
