//
// Created by kaiser on 18-12-3.
//

#pragma once

#include <cstdint>
#include <string>

struct SalesData {
  SalesData &Combine(const SalesData &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
  }

  const std::string &Isbn() const { return book_no; }

  std::string book_no;
  std::int32_t units_sold{};
  double revenue{};
};
