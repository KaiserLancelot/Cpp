//
// Created by kaiser on 18-11-21.
//

#include <cstdint>
#include <iostream>

#include "ex_2_42.h"

int main() {
  double price;
  SalesData sales_data1, sales_data2;

  std::cin >> sales_data1.book_no >> sales_data1.units_sold >> price;
  sales_data1.revenue = sales_data1.units_sold * price;

  std::cin >> sales_data2.book_no >> sales_data2.units_sold >> price;
  sales_data2.revenue = sales_data2.units_sold * price;

  if (sales_data1.book_no == sales_data2.book_no) {
    std::int32_t total_cnt = sales_data1.units_sold + sales_data2.units_sold;
    double total_revenue = sales_data1.revenue + sales_data2.revenue;

    std::cout << sales_data1.book_no << ' ' << total_cnt << ' ' << total_revenue
              << ' ';
    if (total_revenue != 0) {
      std::cout << total_revenue / total_cnt << '\n';
    } else {
      std::cout << "(no sales)\n";
    }
  } else {
    std::cerr << "data must refer to the same ISBN\n";
    return -1;
  }
}
