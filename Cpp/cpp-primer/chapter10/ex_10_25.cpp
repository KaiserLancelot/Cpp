/**
 * @ Author: KaiserLancelot
 * @ Create Time: 2020-05-17 21:48:01
 * @ Modified time: 2020-05-17 21:51:01
 */

#include <algorithm>
#include <cstddef>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

bool CheckSize(const std::string &str, std::size_t size) {
  return std::size(str) < size;
}

void ElimDups(std::vector<std::string> &words) {
  std::sort(std::begin(words), std::end(words));
  words.erase(std::unique(std::begin(words), std::end(words)), std::end(words));
}

void Biggies(std::vector<std::string> &words,
             std::vector<std::string>::size_type sz) {
  using namespace std::placeholders;

  ElimDups(words);
  std::stable_sort(std::begin(words), std::end(words),
                   [](const auto &s1, const auto &s2) {
                     return std::size(s1) < std::size(s2);
                   });
  auto wc{std::partition(std::begin(words), std::end(words),
                         std::bind(&CheckSize, _1, sz))};
  std::for_each(wc, std::end(words),
                [](const auto &s) { std::cout << s << ' '; });
  std::cout << '\n';
}

int main() {
  std::vector<std::string> vs{"aaaaa", "aaaaaa", "cc", "cc", "b"};
  Biggies(vs, 3);
}
