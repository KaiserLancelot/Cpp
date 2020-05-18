//
// Created by kaiser on 18-11-29.
//

#pragma once

#include <cstdint>
#include <iostream>
#include <string>

class SalesData;
std::istream &read(std::istream &is, SalesData &item);

class SalesData {
  friend std::istream &read(std::istream &is, SalesData &item);
  friend std::ostream &print(std::ostream &os, const SalesData &item);
  friend SalesData add(const SalesData &lhs, const SalesData &rhs);

 public:
  SalesData(const std::string &book_no, std::int32_t units_sold, double revenue)
      : book_no_(book_no), units_sold_{units_sold}, revenue_{revenue} {
    std::cout << "const std::string &book_no, std::int32_t units_sold, double "
                 "revenue\n";
  }

  SalesData() : SalesData{"", 0, 0.0} { std::cout << "void\n"; }
  explicit SalesData(const std::string &book_no) : SalesData{book_no, 0, 0} {
    std::cout << "const std::string &book_no\n";
  }

  explicit SalesData(std::istream &is) : SalesData{} {
    read(is, *this);
    std::cout << "std::istream &is\n";
  }

  SalesData &combine(const SalesData &rhs) {
    units_sold_ += rhs.units_sold_;
    revenue_ += rhs.revenue_;
    return *this;
  }

  const std::string &isbn() const { return book_no_; }

 private:
  double avg_price() const {
    return units_sold_ == 0 ? revenue_ / units_sold_ : 0;
  }

  std::string book_no_;
  std::int32_t units_sold_;
  double revenue_;
};

inline std::istream &read(std::istream &is, SalesData &item) {
  double price;
  is >> item.book_no_ >> item.units_sold_ >> price;
  item.revenue_ = item.units_sold_ * price;
  return is;
}

inline std::ostream &print(std::ostream &os, const SalesData &item) {
  os << item.book_no_ << ' ' << item.units_sold_ << ' ' << item.revenue_ << ' '
     << item.avg_price();
  return os;
}

inline SalesData add(const SalesData &lhs, const SalesData &rhs) {
  SalesData sum{lhs};
  sum.combine(rhs);
  return sum;
}
