//
// Created by kaiser on 18-12-3.
//

#ifndef CPP_PRIMER_EX_8_6_H
#define CPP_PRIMER_EX_8_6_H

#include <cstdint>
#include <string>

struct SalesData {
  SalesData &Combine(const SalesData &rhs) {
    units_sold_ += rhs.units_sold_;
    revenue_ += rhs.revenue_;
    return *this;
  }

  const std::string &Isbn() const {
    return book_no_;
  }

  std::string book_no_;
  std::int32_t units_sold_{};
  double revenue_{};
};

#endif //CPP_PRIMER_EX_8_6_H
