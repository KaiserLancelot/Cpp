//
// Created by kaiser on 18-11-29.
//

#pragma once

#include <cstdint>
#include <iostream>
#include <string>

struct SalesData {
  SalesData &combine(const SalesData &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
  }

  const std::string &isbn() const { return book_no; }

  double avg_price() const { return units_sold ? revenue / units_sold : 0; }

  std::string book_no;
  std::int32_t units_sold{};
  double revenue{};
};

inline std::istream &read(std::istream &is, SalesData &item) {
  double price;
  is >> item.book_no >> item.units_sold >> price;
  item.revenue = item.units_sold * price;
  return is;
}

inline std::ostream &print(std::ostream &os, const SalesData &item) {
  os << item.book_no << ' ' << item.units_sold << ' ' << item.revenue << ' '
     << item.avg_price();
  return os;
}

inline SalesData add(const SalesData &lhs, const SalesData &rhs) {
  SalesData sum{lhs};
  sum.combine(rhs);
  return sum;
}
