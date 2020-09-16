//
// Created by kaiser on 18-12-18.
//

#include <iostream>
#include <map>
#include <string>

int main() {
  std::multimap<std::string, std::string> authors{
      {"a", "DMA"}, {"p", "LeetCode"}, {"p", "CLRS"},
      {"w", "FTP"}, {"p", "CP5"},      {"w", "CPP-Concurrency"}};

  std::string author{"p"};
  std::string work{"CP5"};

  auto iter{authors.find(author)};
  auto count{authors.count(author)};

  for (std::size_t i{0}; i < count; ++i) {
    if (iter->second == work) {
      authors.erase(iter);
      break;
    }
    ++iter;
  }

  for (const auto& [author, work] : authors) {
    std::cout << author << ' ' << work << '\n';
  }
}
