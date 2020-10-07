#include <cstdlib>
#include <iostream>

#include "sales_item.h"

int main() {
  SalesItem total;

  if (std::cin >> total) {
    SalesItem trans;
    while (std::cin >> trans) {
      if (trans.isbn() == total.isbn()) {
        total += trans;
      } else {
        std::cout << total << '\n';
        total = trans;
      }
    }
    std::cout << total << '\n';
  } else {
    std::cerr << "No data\n";
    return EXIT_FAILURE;
  }
}
