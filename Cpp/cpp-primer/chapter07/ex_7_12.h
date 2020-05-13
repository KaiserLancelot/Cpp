//
// Created by kaiser on 18-11-29.
//

#pragma once

#include <cstdint>
#include <iostream>
#include <string>

struct SalesData;
inline std::istream &Read(std::istream &is, SalesData &item);

struct SalesData {
  SalesData() = default;
  explicit SalesData(const std::string &book_no) : book_no{book_no} {}

  SalesData(const std::string &book_no, std::int32_t units_sold, double revenue)
      : book_no{book_no}, units_sold{units_sold}, revenue{revenue} {}

  explicit SalesData(std::istream &is) { Read(is, *this); }

  SalesData &Combine(const SalesData &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
  }

  const std::string &Isbn() const { return book_no; }

  double AvgPrice() const { return units_sold ? revenue / units_sold : 0; }

  std::string book_no;
  std::int32_t units_sold{};
  double revenue{};
};

inline std::istream &Read(std::istream &is, SalesData &item) {
  double price;
  is >> item.book_no >> item.units_sold >> price;
  item.revenue = item.units_sold * price;
  return is;
}

inline std::ostream &Print(std::ostream &os, const SalesData &item) {
  os << item.book_no << ' ' << item.units_sold << ' ' << item.revenue << ' '
     << item.AvgPrice();
  return os;
}

inline SalesData Add(const SalesData &lhs, const SalesData &rhs) {
  SalesData sum{lhs};
  sum.Combine(rhs);
  return sum;
}
