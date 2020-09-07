//
// Created by kaiser on 18-11-29.
//

#include <cstdlib>
#include <iostream>

#include "ex_7_12.h"

int main()
{
    SalesData total{std::cin};

    if (!total.isbn().empty()) {
        while (std::cin) {
            SalesData trans{std::cin};
            if (!std::cin) {
                break;
            }

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
