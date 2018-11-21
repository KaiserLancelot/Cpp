//
// Created by kaiser on 18-11-21.
//

#include <iostream>
#include <string>

struct SalesData
{
    std::string book_no_;
    std::int32_t units_sold_{};
    double revenue_{};
};

int main()
{
    double price;
    SalesData sales_data;
    std::cin >> sales_data.book_no_ >> sales_data.units_sold_ >> price;
    sales_data.revenue_ = sales_data.units_sold_ * price;

    std::cout << sales_data.book_no_ << ' ' << sales_data.units_sold_
              << ' ' << sales_data.revenue_ << '\n';
}