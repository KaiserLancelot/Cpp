//
// Created by kaiser on 18-12-26.
//

#include <fstream>
#include <iostream>

#include "ex_15_39_query.h"

int main() {
  std::ifstream file{"story"};
  TextQuery text{file};

  Query query{~Query("Alice")};
  Print(std::cout, query.Eval(text)) << '\n';
}
