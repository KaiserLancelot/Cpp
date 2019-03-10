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

using matches = std::tuple<std::vector<SalesData>::size_type,
                           std::vector<SalesData>::const_iterator,
                           std::vector<SalesData>::const_iterator>;

std::vector<matches> FindBook(const std::vector<std::vector<SalesData>>& files,
                              const std::string& book) {
  std::vector<matches> ret;

  for (auto iter{std::cbegin(files)}; iter != std::cend(files); ++iter) {
    auto [begin, end]{std::equal_range(std::cbegin(*iter), std::cend(*iter),
                                       SalesData{book},
                                       [](const auto& lhs, const auto& rhs) {
                                         return lhs.Isbn() < rhs.Isbn();
                                       })};

    if (begin != end) {
      ret.emplace_back(iter - std::begin(files), begin, end);
    }
  }

  return ret;
}

void ReportResults(std::istream& is, std::ostream& os,
                   const std::vector<std::vector<SalesData>>& files) {
  std::string book;

  while (is >> book) {
    auto result{FindBook(files, book)};
    if (std::empty(result)) {
      os << book << " not found in any stores\n";
      continue;
    }
    for (const auto& store : result) {
      os << "store " << std::get<0>(store) << " sales: "
         << std::accumulate(std::get<1>(store), std::get<2>(store),
                            SalesData{book})
         << '\n';
    }
  }
}

int main() {}