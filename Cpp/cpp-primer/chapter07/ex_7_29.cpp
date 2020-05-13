//
// Created by kaiser on 18-11-29.
//

#include <iostream>

#include "ex_7_29.h"

int main() {
  Screen my_screen(5, 5, 'X');
  my_screen.Move(4, 0).Set('#').Display(std::cout);
  std::cout << '\n';
  my_screen.Display(std::cout);
  std::cout << '\n';
}
