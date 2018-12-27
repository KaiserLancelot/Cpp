//
// Created by kaiser on 18-12-18.
//

#include <map>
#include <string>

int main() {
  std::multimap<std::string, std::string> authors{
      {"a", "DMA"}, {"p", "LeetCode"}, {"p", "CLRS"},
      {"w", "FTP"}, {"p", "CP5"},      {"w", "CPP-Concurrency"}};

  std::string author("p");

  auto iter{authors.find(author)};
  auto count{authors.count(author)};

  for (std::size_t i{0}; i < count; ++i) {
    iter = authors.erase(iter);
  }
}