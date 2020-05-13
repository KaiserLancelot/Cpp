//
// Created by kaiser on 18-11-29.
//

#include <cstdlib>
#include <iostream>

#include "ex_7_21.h"

int main() {
  SalesData total;

  if (Read(std::cin, total)) {
    SalesData trans;
    while (Read(std::cin, trans)) {
      if (total.Isbn() == trans.Isbn()) {
        total.Combine(trans);
      } else {
        Print(std::cout, total) << '\n';
        total = trans;
      }
    }
    Print(std::cout, total) << '\n';
  } else {
    std::cerr << "no data" << std::endl;
    return EXIT_FAILURE;
  }
}
