#include <cstdint>
#include <iostream>

#include "ex_02_42.h"
#include "float_point.h"

int main() {
  double price;
  SalesData sales_data1;
  SalesData sales_data2;

  std::cin >> sales_data1.book_no_ >> sales_data1.units_sold_ >> price;
  sales_data1.revenue_ = sales_data1.units_sold_ * price;

  std::cin >> sales_data2.book_no_ >> sales_data2.units_sold_ >> price;
  sales_data2.revenue_ = sales_data2.units_sold_ * price;

  if (sales_data1.book_no_ == sales_data2.book_no_) {
    std::int32_t total_cnt = sales_data1.units_sold_ + sales_data2.units_sold_;
    double total_revenue = sales_data1.revenue_ + sales_data2.revenue_;

    std::cout << sales_data1.book_no_ << ' ' << total_cnt << ' '
              << total_revenue << ' ';
    if (!float_point_equal(total_revenue, 0.0)) {
      std::cout << total_revenue / total_cnt << '\n';
    } else {
      std::cout << "(no sales)\n";
    }
  } else {
    std::cerr << "data must refer to the same ISBN\n";
    return -1;
  }
}
