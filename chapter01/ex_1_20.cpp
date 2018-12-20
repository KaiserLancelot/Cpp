//
// Created by kaiser on 18-11-20.
//

#include "Sales_item.h"
#include <iostream>

int main() {
  Sales_item item;

  while (std::cin >> item)
    std::cout << item << '\n';
}