//
// Created by kaiser on 18-11-21.
//

#include <iostream>
#include <string>

struct SalesData
{
    std::string book_no_;
    int units_sold_ = 0;
    double revenue_ = 0;
};

int main()
{
    SalesData total;
    double price;

    if (std::cin >> total.book_no_ >> total.units_sold_ >> price)
    {
        total.revenue_ = total.units_sold_ * price;
        SalesData trans;

        while (std::cin >> trans.book_no_ >> trans.units_sold_ >> price)
        {
            trans.revenue_ = trans.units_sold_ * price;
            if (total.book_no_ == trans.book_no_)
            {
                total.units_sold_ += trans.units_sold_;
                total.revenue_ += trans.revenue_;
            }
            else
            {
                std::cout << total.book_no_ << ' ' << total.units_sold_ << ' '
                          << total.revenue_ << '\n';
                if (total.revenue_ != 0)
                    std::cout << total.revenue_ / total.units_sold_ << '\n';
                else
                    std::cout << "(no sales)" << '\n';

                total.book_no_ = trans.book_no_;
                total.units_sold_ = trans.units_sold_;
                total.revenue_ = trans.revenue_;
            }
        }
        std::cout << total.book_no_ << ' ' << total.units_sold_ << ' '
                  << total.revenue_ << '\n';
        if (total.revenue_ != 0)
            std::cout << total.revenue_ / total.units_sold_ << '\n';
        else
            std::cout << "(no sales)" << '\n';
    }
    else
    {
        std::cerr << "no data\n";
        return -1;
    }
}