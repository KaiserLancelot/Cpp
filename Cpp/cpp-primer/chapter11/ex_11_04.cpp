//
// Created by kaiser on 18-12-18.
//

#include <algorithm>
#include <cctype>
#include <cstdint>
#include <iostream>
#include <string>
#include <unordered_map>

std::string Fun(const std::string &str) {
  auto iter{std::find_if(std::begin(str), std::end(str), ispunct)};
  std::string ret{str.substr(0, iter - std::begin(str))};
  for (auto &c : ret) {
    c = std::tolower(c);
  }
  return ret;
}

int main() {
  std::unordered_map<std::string, std::int32_t> word_count;
  std::string word;
  while (std::cin >> word) {
    ++word_count[Fun(word)];
  }

  for (const auto &[s, count] : word_count) {
    std::cout << s << ' ' << count << '\n';
  }
}
