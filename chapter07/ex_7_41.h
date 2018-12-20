//
// Created by kaiser on 18-11-29.
//

#ifndef CPP_PRIMER_EX_7_41_H
#define CPP_PRIMER_EX_7_41_H

#include <cstdint>
#include <string>
#include <iostream>

class SalesData;
std::istream &Read(std::istream &is, SalesData &item);

class SalesData {
  friend std::istream &Read(std::istream &is, SalesData &item);
  friend std::ostream &Print(std::ostream &os, const SalesData &item);
  friend SalesData Add(const SalesData &lhs, const SalesData &rhs);
 public:
  SalesData(const std::string &book_no, std::int32_t units_sold,
            double revenue) : book_no_(book_no), units_sold_{units_sold},
                              revenue_{revenue} {
    std::cout << "const std::string &book_no, std::int32_t units_sold, double revenue\n";
  }

  SalesData() : SalesData{"", 0, 0.0} {
    std::cout << "void\n";
  }
  explicit SalesData(const std::string &book_no) : SalesData{book_no, 0, 0} {
    std::cout << "const std::string &book_no\n";
  }

  explicit SalesData(std::istream &is) : SalesData{} {
    Read(is, *this);
    std::cout << "std::istream &is\n";
  }

  SalesData &Combine(const SalesData &rhs) {
    units_sold_ += rhs.units_sold_;
    revenue_ += rhs.revenue_;
    return *this;
  }

  const std::string &Isbn() const {
    return book_no_;
  }
 private:
  double AvgPrice() const {
    return units_sold_ ? revenue_ / units_sold_ : 0;
  }

  std::string book_no_;
  std::int32_t units_sold_;
  double revenue_;
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

#endif //CPP_PRIMER_EX_7_41_H
