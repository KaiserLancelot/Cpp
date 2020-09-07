//
// Created by kaiser on 18-12-25.
//

#include "ex_15_30.h"

double Basket::TotalReceipt(std::ostream& os) const
{
    double sum{};

    for (auto iter{std::cbegin(items_)}; iter != std::cend(items_);
         iter = items_.upper_bound(*iter)) {
        sum += PrintTotal(os, **iter, items_.count(*iter));
    }
    os << "Total Sale: " << sum << '\n';
    return sum;
}
