//
// Created by kaiser on 18-11-20.
//

#include <iostream>
#include "Sales_item.h"

int main() {
  Sales_item item;

  while (std::cin >> item) {
    std::cout << item << '\n';
  }
}