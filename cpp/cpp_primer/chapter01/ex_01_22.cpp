#include <cstdlib>
#include <iostream>

#include "sales_item.h"

int main() {
  SalesItem sum;

  if (std::cin >> sum) {
    SalesItem item;
    while (std::cin >> item) {
      if (item.isbn() == sum.isbn()) {
        sum += item;
      } else {
        std::cout << sum << '\n';
        sum = item;
      }
    }
    std::cout << sum << '\n';
  } else {
    std::cerr << "No data\n";
    return EXIT_FAILURE;
  }
}
