//
// Created by kaiser on 18-12-19.
//

#include "ex_12_22.h"

#include <iostream>

int main() {
  const StrBlob sb{"a", "b", "c"};

  for (auto begin{sb.begin()}; begin.not_equal(sb.end()); begin.incr()) {
    std::cout << begin.deref() << '\n';
  }
}
