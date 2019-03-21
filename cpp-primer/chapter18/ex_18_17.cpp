//
// Created by kaiser on 19-3-14.
//

#include <iostream>

namespace exercise {
int ivar = 10;
double dvar = 0;
const int limit = 1000;
}  // namespace exercise

int ivar = 0;

// using exercise::ivar, exercise::dvar, exercise::limit;

int main() {
  using exercise::ivar, exercise::dvar, exercise::limit;
  // double dvar = 3.1416;
  int iobj = limit + 1;
  std::cout << ivar << '\n';
  std::cout << ::ivar << '\n';
}