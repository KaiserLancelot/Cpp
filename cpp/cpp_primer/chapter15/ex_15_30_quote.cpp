//
// Created by kaiser on 18-12-25.
//

#include "ex_15_30_quote.h"

double PrintTotal(std::ostream& os, const Quote& item, std::size_t n)
{
    double ret{item.NetPrice(n)};
    os << "ISBN: " << item.Isbn() << " # sold: " << n << " total due: " << ret
       << '\n';
    return ret;
}
