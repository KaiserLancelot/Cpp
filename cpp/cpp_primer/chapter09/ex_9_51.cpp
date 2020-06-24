//
// Created by kaiser on 18-12-5.
//

#include <iostream>

#include "ex_9_51.h"

int main() {
  Date date1{"January 1, 1900"};
  print(std::cout, date1) << '\n';

  Date date2{"1/1/1900"};
  print(std::cout, date2) << '\n';

  Date date3{"Jan 1 1900"};
  print(std::cout, date3) << '\n';
}
