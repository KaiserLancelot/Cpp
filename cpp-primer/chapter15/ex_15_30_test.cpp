//
// Created by kaiser on 18-12-25.
//

#include <iostream>
#include <memory>
#include <vector>

#include "ex_15_30.h"

int main() {
  Basket v;

  for (std::int32_t i{1}; i < 10; ++i) {
    v.AddItem(BulkQuote{"sss", i * 10.1, 10, 0.3});
  }

  v.TotalReceipt(std::cout);
}