//
// Created by kaiser on 18-12-17.
//

#include <algorithm>
#include <iostream>
#include <vector>

#include "ex_7_12.h"

bool compare_isbn(const SalesData& lhs, const SalesData& rhs) {
  return lhs.isbn() < rhs.isbn();
}

int main() {
  std::vector<SalesData> vector{SalesData{"aa"}, SalesData{"aaaa"},
                                SalesData{"aaa"}, SalesData{"z"}};
  std::sort(std::begin(vector), std::end(vector), compare_isbn);

  for (const auto& ele : vector) {
    std::cout << ele.isbn() << '\n';
  }
}
