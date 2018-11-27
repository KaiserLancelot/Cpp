//
// Created by kaiser on 18-11-20.
//

#include "Sales_item.h"
#include <iostream>

int main() {
    Sales_item item1, item2;

    std::cin >> item1 >> item2;
    if (item1.isbn() == item2.isbn())
        std::cout << item1 + item2;
    else
        std::cerr << "Different ISBN.\n";
}