//
// Created by kaiser on 18-12-25.
//

#include "ex_15_28.h"

#include <iostream>
#include <memory>
#include <vector>

int main() {
  std::vector<std::shared_ptr<Quote>> v;

  for (std::int32_t i{0}; i < 10; ++i) {
    v.push_back(std::make_shared<BulkQuote>("sss", i * 10.1, 10, 0.3));
  }

  double price{};

  for (const auto &ele : v) {
    price += ele->NetPrice(20);
  }

  std::cout << price << '\n';
}
