//
// Created by kaiser on 18-12-17.
//

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void elim_dups(std::vector<std::string>& words) {
  std::sort(std::begin(words), std::end(words));
  words.erase(std::unique(std::begin(words), std::end(words)), std::end(words));
}

void biggies(std::vector<std::string>& words,
             std::vector<std::string>::size_type sz) {
  elim_dups(words);
  std::stable_sort(std::begin(words), std::end(words),
                   [](const auto& s1, const auto& s2) {
                     return std::size(s1) < std::size(s2);
                   });
  auto wc{std::partition(std::begin(words), std::end(words),
                         [sz](const auto& s) { return std::size(s) < sz; })};
  std::for_each(wc, std::end(words),
                [](const auto& s) { std::cout << s << ' '; });
  std::cout << '\n';
}

int main() {
  std::vector<std::string> vs{"aaaaa", "aaaaaa", "cc", "cc", "b"};
  biggies(vs, 3);
}
