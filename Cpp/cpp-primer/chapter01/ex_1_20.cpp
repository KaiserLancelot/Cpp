//
// Created by kaiser on 18-11-20.
//

#include <iostream>

#include "Sales_item.h"

int main() {
  SalesItem item;

  while (std::cin >> item) {
    std::cout << item << '\n';
  }
}
