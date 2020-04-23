//
// Created by kaiser on 19-3-14.
//

#ifndef CPP_PRIMER_EX_18_09_H
#define CPP_PRIMER_EX_18_09_H

#include <cstdint>
#include <iostream>
#include <stdexcept>
#include <string>

class OutOfStock : public std::runtime_error {
 public:
  explicit OutOfStock(const std::string &s) : std::runtime_error{s} {}
};

class IsbnMismatch : public std::logic_error {
 public:
  explicit IsbnMismatch(const std::string &s) : std::logic_error{s} {}
  IsbnMismatch(const std::string &s, const std::string &left,
               const std::string &right)
      : std::logic_error{s}, left_{left}, right_{right} {}

  const std::string left_, right_;
};

class SalesData {
  friend std::ostream &operator<<(std::ostream &os, const SalesData &item);
  friend std::istream &operator>>(std::istream &is, SalesData &item);

 public:
  SalesData() = default;
  explicit SalesData(const std::string &book_no);
  SalesData(const std::string &book_no, std::int32_t units_sold,
            double revenue);
  explicit SalesData(std::istream &is);
  SalesData &operator==(const std::string &s);
  SalesData &operator+=(const SalesData &rhs);
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

#endif  // CPP_PRIMER_EX_18_09_H
