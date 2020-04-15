//
// Created by kaiser on 18-11-21.
//

#include <cstdint>
#include <iostream>
#include <string>

struct SalesData {
  std::string book_no;
  std::int32_t units_sold{};
  double revenue{};
};

int main() {
  SalesData total;
  double price;

  if (std::cin >> total.book_no >> total.units_sold >> price) {
    total.revenue = total.units_sold * price;
    SalesData trans;

    while (std::cin >> trans.book_no >> trans.units_sold >> price) {
      trans.revenue = trans.units_sold * price;
      if (total.book_no == trans.book_no) {
        total.units_sold += trans.units_sold;
        total.revenue += trans.revenue;
      } else {
        std::cout << total.book_no << ' ' << total.units_sold << ' '
                  << total.revenue << '\n';
        if (total.revenue != 0)
          std::cout << total.revenue / total.units_sold << '\n';
        else
          std::cout << "(no sales)" << '\n';

        total.book_no = trans.book_no;
        total.units_sold = trans.units_sold;
        total.revenue = trans.revenue;
      }
    }
    std::cout << total.book_no << ' ' << total.units_sold << ' '
              << total.revenue << '\n';
    if (total.revenue != 0)
      std::cout << total.revenue / total.units_sold << '\n';
    else
      std::cout << "(no sales)" << '\n';
  } else {
    std::cerr << "no data\n";
    return -1;
  }
}
