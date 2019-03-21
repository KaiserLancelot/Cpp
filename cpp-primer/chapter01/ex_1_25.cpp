//
// Created by kaiser on 18-11-20.
//

#include <iostream>
#include "Sales_item.h"

int main() {
  Sales_item total;

  if (std::cin >> total) {
    Sales_item trans;
    while (std::cin >> trans) {
      if (trans.isbn() == total.isbn())
        total += trans;
      else {
        std::cout << total << '\n';
        total = trans;
      }
    }
    std::cout << total << '\n';
  } else {
    std::cerr << "No data?!" << '\n';
    return -1;
  }
}