//
// Created by kaiser on 18-12-23.
//

#ifndef CPP_PRIMER_EX_14_13_H
#define CPP_PRIMER_EX_14_13_H

#include <cstdint>
#include <string>
#include <iostream>

class SalesData {
  friend std::ostream &operator<<(std::ostream &os, const SalesData &item);
  friend std::istream &operator>>(std::istream &is, SalesData &item);
 public:
  SalesData() = default;
  explicit SalesData(const std::string &book_no);
  SalesData(const std::string &book_no, std::int32_t units_sold, double revenue);
  explicit SalesData(std::istream &is);
  SalesData &operator+=(const SalesData &rhs);
  SalesData &operator-=(const SalesData &rhs);
  const std::string &Isbn() const;
 private:
  double AvgPrice() const;

  std::string book_no_;
  std::int32_t units_sold_{};
  double revenue_{};
};

std::ostream &operator<<(std::ostream &os, const SalesData &item);
std::istream &operator>>(std::istream &is, SalesData &item);
SalesData operator+(const SalesData &lhs, const SalesData &rhs);
SalesData operator-(const SalesData &lhs, const SalesData &rhs);

#endif //CPP_PRIMER_EX_14_13_H
