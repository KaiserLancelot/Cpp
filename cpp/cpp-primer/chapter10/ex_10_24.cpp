/**
 * @ Author: KaiserLancelot
 * @ Create Time: 2020-05-17 21:43:51
 * @ Modified time: 2020-05-17 21:51:37
 */

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <iostream>
#include <vector>

bool check_size(const std::string &str, std::size_t size) {
  return std::size(str) < size;
}

int main() {
  using namespace std::placeholders;
  std::vector<std::int32_t> v{1, 2, 3, 4, 5, 6};
  std::string str{"aaa"};
  std::cout << *std::find_if(std::begin(v), std::end(v),
                             std::bind(&check_size, str, _1))
            << '\n';
}
