//
// Created by kaiser on 18-12-24.
//

#ifndef CPP_PRIMER_EX_15_03_H
#define CPP_PRIMER_EX_15_03_H

#include <cstddef>
#include <cstdint>
#include <iostream>
#include <string>

class Quote {
 public:
  Quote() = default;
  Quote(const std::string &book_no, double price)
      : price_{price}, book_no_{book_no} {}
  virtual ~Quote() = default;
  std::string Isbn() const { return book_no_; }
  virtual double NetPrice(std::int32_t n) const { return n * price_; }

 protected:
  double price_{};

 private:
  std::string book_no_;
};

double PrintTotal(std::ostream &os, const Quote &item, std::size_t n);

#endif  // CPP_PRIMER_EX_15_03_H
