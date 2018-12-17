//
// Created by kaiser on 18-11-29.
//

#include "ex_7_12.h"
#include <iostream>
#include <cstdlib>

int main() {
    SalesData total(std::cin);

    if (!total.Isbn().empty()) {
        while (std::cin) {
            SalesData trans(std::cin);
            if (!std::cin)
                break;

            if (total.Isbn() == trans.Isbn()) {
                total.Combine(trans);
            } else {
                Print(std::cout, total) << '\n';
                total = trans;
            }
        }
        Print(std::cout, total) << '\n';
    } else {
        std::cerr << "no data\n";
        return EXIT_FAILURE;
    }
}