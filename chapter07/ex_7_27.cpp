//
// Created by kaiser on 18-11-29.
//

#include "ex_7_27.h"
#include <iostream>

int main() {
  Screen my_screen(5, 5, 'X');
  my_screen.Move(4, 0).Set('#').Display(std::cout);
  std::cout << '\n';
  my_screen.Display(std::cout);
  std::cout << '\n';
}