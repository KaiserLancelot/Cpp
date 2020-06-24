//
// Created by kaiser on 18-12-3.
//

#pragma once

#include <cstdint>
#include <string>

struct SalesData {
  SalesData &combine(const SalesData &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
  }

  const std::string &isbn() const { return book_no; }

  std::string book_no;
  std::int32_t units_sold{};
  double revenue{};
};
