//
// Created by kaiser on 18-12-3.
//

#include <cstdlib>
#include <fstream>
#include <iostream>

#include "ex_8_06.h"

int main(int argc, char* argv[]) {
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
  if (ifs >> total.book_no >> total.units_sold >> total.revenue) {
    SalesData trans;
    while (ifs >> trans.book_no >> trans.units_sold >> trans.revenue) {
      if (total.isbn() == trans.isbn()) {
        total.combine(trans);
      } else {
        ofs << total.book_no << " " << total.units_sold << " " << total.revenue
            << '\n';
        total = trans;
      }
    }
    ofs << total.book_no << " " << total.units_sold << " " << total.revenue
        << '\n';
  } else {
    std::cerr << "no data\n";
    return EXIT_FAILURE;
  }
}
