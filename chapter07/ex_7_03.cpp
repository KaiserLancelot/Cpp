//
// Created by kaiser on 18-11-29.
//

#include "ex_7_02.h"
#include <iostream>
#include <cstdlib>

int main() {
    SalesData total;
    if (std::cin >> total.book_no_ >> total.units_sold_ >> total.revenue_) {
        SalesData trans;
        while (std::cin >> trans.book_no_ >> trans.units_sold_ >> trans.revenue_) {
            if (total.Isbn() == trans.Isbn()) {
                total.Combine(trans);
            } else {
                std::cout << total.book_no_ << " " << total.units_sold_
                          << " " << total.revenue_ << '\n';
                total = trans;
            }
        }
        std::cout << total.book_no_ << " " << total.units_sold_
                  << " " << total.revenue_ << '\n';
    } else {
        std::cerr << "no data\n";
        return EXIT_FAILURE;
    }
}