//
// Created by kaiser on 18-11-20.
//

#include <cstdlib>
#include <iostream>

#include "Sales_item.h"

int main()
{
    SalesItem sum;

    if (std::cin >> sum) {
        SalesItem item;
        while (std::cin >> item) {
            if (item.isbn() == sum.isbn()) {
                sum += item;
            }
            else {
                std::cout << sum << '\n';
                sum = item;
            }
        }
        std::cout << sum << '\n';
    }
    else {
        std::cerr << "No data." << std::endl;
        return EXIT_FAILURE;
    }
}
