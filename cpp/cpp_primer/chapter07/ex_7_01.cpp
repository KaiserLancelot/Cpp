/**
 * @ Author: KaiserLancelot
 * @ Create Time: 2020-05-14 04:55:36
 * @ Modified time: 2020-05-15 02:16:30
 */

#include <cstdlib>
#include <iostream>

#include "ex_2_42.h"

int main()
{
    SalesData total;

    if (std::cin >> total.book_no >> total.units_sold >> total.revenue) {
        SalesData trans;
        while (std::cin >> trans.book_no >> trans.units_sold >> trans.revenue) {
            if (total.book_no == trans.book_no) {
                total.units_sold += trans.units_sold;
                total.revenue += trans.revenue;
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
