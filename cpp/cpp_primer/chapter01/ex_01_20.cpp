#include <iostream>

#include "Sales_item.h"

int main() {
  SalesItem item;

  while (std::cin >> item) {
    std::cout << item << '\n';
  }
}
