//
// Created by kaiser on 18-11-29.
//

#ifndef CPP_PRIMER_EX_7_6_H
#define CPP_PRIMER_EX_7_6_H

#include <cstdint>
#include <string>
#include <iostream>

struct SalesData {
    SalesData &Combine(const SalesData &rhs) {
        units_sold_ += rhs.units_sold_;
        revenue_ += rhs.revenue_;
        return *this;
    }

    const std::string &Isbn() const {
        return book_no_;
    }

    double AvgPrice() const {
        return units_sold_ ? revenue_ / units_sold_ : 0;
    }

    std::string book_no_;
    std::int32_t units_sold_{};
    double revenue_{};
};

inline std::istream &Read(std::istream &is, SalesData &item) {
    double price;
    is >> item.book_no_ >> item.units_sold_ >> price;
    item.revenue_ = item.units_sold_ * price;
    return is;
}

inline std::ostream &Print(std::ostream &os, const SalesData &item) {
    os << item.book_no_ << ' ' << item.units_sold_ << ' ' <<
       item.revenue_ << ' ' << item.AvgPrice();
    return os;
}

inline SalesData Add(const SalesData &lhs, const SalesData &rhs) {
    SalesData sum{lhs};
    sum.Combine(rhs);
    return sum;
}

#endif //CPP_PRIMER_EX_7_6_H
