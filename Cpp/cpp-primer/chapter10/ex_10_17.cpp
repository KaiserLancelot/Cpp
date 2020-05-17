//
// Created by kaiser on 18-12-17.
//

#include "ex_7_12.h"

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<SalesData> vector{SalesData{"aa"}, SalesData{"aaaa"},
                                SalesData{"aaa"}, SalesData{"z"}};
  std::sort(
      std::begin(vector), std::end(vector),
      [](const auto &lhs, const auto &rhs) { return lhs.Isbn() < rhs.Isbn(); });

  for (const auto &ele : vector) {
    std::cout << ele.Isbn() << '\n';
  }
}
