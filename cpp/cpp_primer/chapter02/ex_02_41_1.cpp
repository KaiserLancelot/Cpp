#include <iostream>

#include "ex_02_42.h"

int main() {
  double price;
  SalesData sales_data;
  std::cin >> sales_data.book_no_ >> sales_data.units_sold_ >> price;
  sales_data.revenue_ = sales_data.units_sold_ * price;

  std::cout << sales_data.book_no_ << ' ' << sales_data.units_sold_ << ' '
            << sales_data.revenue_ << '\n';
}
