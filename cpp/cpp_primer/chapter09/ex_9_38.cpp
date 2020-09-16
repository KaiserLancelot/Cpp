/**
 * @ Author: KaiserLancelot
 * @ Create Time: 2020-05-16 06:08:43
 * @ Modified time: 2020-05-16 06:11:59
 */

#include <iostream>
#include <string>
#include <vector>

int main() {
  std::vector<std::string> v;

  for (std::int32_t i{0}; i < 50; ++i) {
    v.emplace_back("str");
    std::cout << v.capacity() << '\n';
  }
}
