//
// Created by kaiser on 18-11-29.
//

#include "ex_7_21.h"
#include <cstdlib>
#include <iostream>

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
    std::cerr << "no data\n";
    return EXIT_FAILURE;
  }
}