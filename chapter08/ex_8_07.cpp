//
// Created by kaiser on 18-12-3.
//

#include "ex_8_07.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cerr << "error\n";
        return EXIT_FAILURE;
    }

    std::ifstream ifs{argv[1]};
    std::ofstream ofs{argv[2]};

    if (!ifs || !ofs) {
        std::cerr << "can't open file\n";
        return EXIT_FAILURE;
    }

    SalesData total;
    if (ifs >> total.book_no_ >> total.units_sold_ >> total.revenue_) {
        SalesData trans;
        while (ifs >> trans.book_no_ >> trans.units_sold_ >> trans.revenue_) {
            if (total.Isbn() == trans.Isbn()) {
                total.Combine(trans);
            } else {
                ofs << total.book_no_ << " " << total.units_sold_
                    << " " << total.revenue_ << '\n';
                total = trans;
            }
        }
        ofs << total.book_no_ << " " << total.units_sold_
            << " " << total.revenue_ << '\n';
    } else {
        std::cerr << "no data\n";
        return EXIT_FAILURE;
    }
}