//
// Created by kaiser on 18-12-19.
//

#include "ex_12_22.h"

#include <iostream>

int main() {
  const StrBlob sb{"a", "b", "c"};

  for (auto begin{sb.begin()}; begin.NotEqual(sb.end()); begin.Incr()) {
    std::cout << begin.Deref() << '\n';
  }
}