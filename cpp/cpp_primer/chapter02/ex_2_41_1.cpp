//
// Created by kaiser on 18-11-21.
//

#include <iostream>

#include "ex_2_42.h"

int main()
{
    double price;
    SalesData sales_data;
    std::cin >> sales_data.book_no >> sales_data.units_sold >> price;
    sales_data.revenue = sales_data.units_sold * price;

    std::cout << sales_data.book_no << ' ' << sales_data.units_sold << ' '
              << sales_data.revenue << '\n';
}
