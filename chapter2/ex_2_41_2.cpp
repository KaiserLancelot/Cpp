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
    SalesData sales_data1, sales_data2;

    std::cin >> sales_data1.book_no_ >> sales_data1.units_sold_ >> price;
    sales_data1.revenue_ = sales_data1.units_sold_ * price;

    std::cin >> sales_data2.book_no_ >> sales_data2.units_sold_ >> price;
    sales_data2.revenue_ = sales_data2.units_sold_ * price;

    if (sales_data1.book_no_ == sales_data2.book_no_)
    {
        int total_cnt = sales_data1.units_sold_ + sales_data2.units_sold_;
        double total_revenue = sales_data1.revenue_ + sales_data2.revenue_;

        std::cout << sales_data1.book_no_ << ' ' << total_cnt << ' ' <<
                  total_revenue << ' ';
        if (total_revenue != 0)
            std::cout << total_revenue / total_cnt << '\n';
        else
            std::cout << "(no sales)\n";
    }
    else
    {
        std::cerr << "data must refer to the same ISBN\n";
        return -1;
    }
}