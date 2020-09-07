//
// Created by kaiser on 18-12-25.
//

#ifndef CPP_PRIMER_EX_15_30_H
#define CPP_PRIMER_EX_15_30_H

#include <iostream>
#include <memory>
#include <set>

#include "ex_15_30_quote.h"

class Basket {
public:
    void AddItem(const Quote& sale)
    {
        items_.insert(std::shared_ptr<Quote>{sale.clone()});
    }
    void AddItem(Quote&& sale)
    {
        items_.insert(std::shared_ptr<Quote>{std::move(sale).clone()});
    }
    double TotalReceipt(std::ostream& os) const;

private:
    static bool less(const std::shared_ptr<Quote>& lhs,
                     const std::shared_ptr<Quote>& rhs)
    {
        return lhs->Isbn() < rhs->Isbn();
    }
    std::multiset<std::shared_ptr<Quote>, decltype(less)*> items_{less};
};

#endif // CPP_PRIMER_EX_15_30_H
