//
// Created by kaiser on 18-11-29.
//

#include <cstdlib>
#include <iostream>

#include "ex_7_02.h"

int main()
{
    SalesData total;

    if (std::cin >> total.book_no >> total.units_sold >> total.revenue) {
        SalesData trans;
        while (std::cin >> trans.book_no >> trans.units_sold >> trans.revenue) {
            if (total.isbn() == trans.isbn()) {
                total.combine(trans);
            }
            else {
                std::cout << total.book_no << " " << total.units_sold << " "
                          << total.revenue << '\n';
                total = trans;
            }
        }
        std::cout << total.book_no << " " << total.units_sold << " "
                  << total.revenue << '\n';
    }
    else {
        std::cerr << "no data" << std::endl;
        return EXIT_FAILURE;
    }
}
