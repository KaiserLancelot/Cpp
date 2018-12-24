//
// Created by kaiser on 18-12-24.
//

#ifndef CPP_PRIMER_EX_15_07_H
#define CPP_PRIMER_EX_15_07_H

#include <cstdint>

#include "ex_15_03.h"

class LimitQuote : public Quote {
 public:
  LimitQuote(const std::string &book_no, double price,
             std::int32_t max_qty, double discount_)
      : Quote(book_no, price), max_qty(max_qty), discount_(discount_) {}

  double NetPrice(std::int32_t n) const override {
    if (n < max_qty)
      return n * price_ * (1 - discount_);
    else
      return n * price_;
  }
 private:
  std::int32_t max_qty{};
  double discount_{};
};

#endif //CPP_PRIMER_EX_15_07_H
