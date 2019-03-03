//
// Created by kaiser on 19-3-3.
//

#include <iostream>

#include "ex_16_15.h"

int main() {
  Screen<5, 5> scr('c');
  Screen<5, 5> scr2;

  std::cout << scr;
  std::cin >> scr2;
  std::cout << scr2;
}