//
// Created by kaiser on 18-12-24.
//

#ifndef CPP_PRIMER_EX_15_05_H
#define CPP_PRIMER_EX_15_05_H

#include <cstdint>

#include "ex_15_03.h"

class BulkQuote : public Quote {
 public:
  BulkQuote(const std::string& book_no, double price, std::int32_t min_qty,
            double discount)
      : Quote(book_no, price), min_qty_{min_qty}, discount_{discount} {}

  double NetPrice(std::int32_t n) const override {
    if (n >= min_qty_)
      return n * (1 - discount_) * price_;
    else
      return n * price_;
  }

 private:
  std::int32_t min_qty_{};
  double discount_{};
};

#endif  // CPP_PRIMER_EX_15_05_H
