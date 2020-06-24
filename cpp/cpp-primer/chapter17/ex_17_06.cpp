//
// Created by kaiser on 19-3-10.
//

#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <tuple>
#include <vector>

#include "sales_data.h"

class Matches {
public:
  Matches(std::vector<SalesData>::size_type index,
          std::vector<SalesData>::const_iterator begin,
          std::vector<SalesData>::const_iterator end)
      : index_{index}, begin_{begin}, end_{end} {}

  std::vector<SalesData>::size_type index_{};
  std::vector<SalesData>::const_iterator begin_;
  std::vector<SalesData>::const_iterator end_;
};

std::vector<Matches> FindBook(const std::vector<std::vector<SalesData>> &files,
                              const std::string &book) {
  std::vector<Matches> ret;

  for (auto iter{std::cbegin(files)}; iter != std::cend(files); ++iter) {
    auto [begin, end]{std::equal_range(std::cbegin(*iter), std::cend(*iter),
                                       SalesData{book},
                                       [](const auto &lhs, const auto &rhs) {
                                         return lhs.Isbn() < rhs.Isbn();
                                       })};

    if (begin != end) {
      ret.emplace_back(iter - std::begin(files), begin, end);
    }
  }

  return ret;
}

void ReportResults(std::istream &is, std::ostream &os,
                   const std::vector<std::vector<SalesData>> &files) {
  std::string book;

  while (is >> book) {
    auto result{FindBook(files, book)};
    if (std::empty(result)) {
      os << book << " not found in any stores\n";
      continue;
    }
    for (const auto &store : result) {
      os << "store " << store.index_ << " sales: "
         << std::accumulate(store.begin_, store.end_, SalesData{book}) << '\n';
    }
  }
}

int main() {}
