//
// Created by kaiser on 18-11-29.
//

#include <cstdlib>
#include <iostream>

#include "ex_7_21.h"

int main()
{
    SalesData total;

    if (read(std::cin, total)) {
        SalesData trans;
        while (read(std::cin, trans)) {
            if (total.isbn() == trans.isbn()) {
                total.combine(trans);
            }
            else {
                print(std::cout, total) << '\n';
                total = trans;
            }
        }
        print(std::cout, total) << '\n';
    }
    else {
        std::cerr << "no data" << std::endl;
        return EXIT_FAILURE;
    }
}
