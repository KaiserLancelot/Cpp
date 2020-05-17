/**
 * @ Author: KaiserLancelot
 * @ Create Time: 2020-05-17 21:38:30
 * @ Modified time: 2020-05-17 21:51:44
 */

#include <algorithm>
#include <cstddef>
#include <functional>
#include <iostream>
#include <vector>

bool CheckSize(const std::string &str, std::size_t size) {
  return std::size(str) < size;
}

int main() {
  using namespace std::placeholders;
  std::vector<std::string> v{"aaa", "aaaaaaaaaaa", "a"};
  std::cout << std::count_if(std::begin(v), std::end(v),
                             std::bind(&CheckSize, _1, 6))
            << '\n';
}
