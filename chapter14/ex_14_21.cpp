//
// Created by kaiser on 18-12-23.
//

#include "ex_14_21.h"

SalesData::SalesData(const std::string &book_no)
    : book_no_(book_no) {}

SalesData::SalesData(const std::string &book_no, std::int32_t units_sold, double revenue)
    : book_no_(book_no), units_sold_{units_sold}, revenue_{revenue} {}

SalesData::SalesData(std::istream &is) {
  is >> *this;
}

SalesData &SalesData::operator+=(const SalesData &rhs) {
  auto sum{*this + rhs};
  *this = sum;
  return *this;
}

const std::string &SalesData::Isbn() const {
  return book_no_;
}

double SalesData::AvgPrice() const {
  return units_sold_ ? revenue_ / units_sold_ : 0;
}

std::ostream &operator<<(std::ostream &os, const SalesData &item) {
  os << item.book_no_ << ' ' << item.units_sold_ << ' ' <<
     item.revenue_ << ' ' << item.AvgPrice();
  return os;
}

std::istream &operator>>(std::istream &is, SalesData &item) {
  double price;
  is >> item.book_no_ >> item.units_sold_ >> price;
  if (is) {
    item.revenue_ = item.units_sold_ * price;
  } else {
    item = SalesData{};
  }

  return is;
}

SalesData operator+(const SalesData &lhs, const SalesData &rhs) {
  auto sum{lhs};
  sum.units_sold_ += rhs.units_sold_;
  sum.revenue_ += rhs.units_sold_;
  return sum;
}
