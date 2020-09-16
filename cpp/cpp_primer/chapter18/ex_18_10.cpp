//
// Created by kaiser on 19-3-14.
//

#include <iostream>

#include "ex_18_09.h"

int main() {
  SalesData item1{"a"}, item2{"b"};
  try {
    auto item3{item1 + item2};
  } catch (const IsbnMismatch& err) {
    std::cout << err.what() << ": left(" << err.left_ << ") right("
              << err.right_ << ")\n";
  }
}
