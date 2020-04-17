//
// Created by kaiser on 2020/4/18.
//

#include <cstdint>
#include <iostream>
#include <vector>

int main() {
  std::vector<std::int32_t> v{1, 2, 3, 4, 5, 5, 3};

  for (auto i : v) {
    std::cout << i << ' ';
  }
  std::cout << '\n';

  // 删除了, 而不是想成员函数那样移动
  // 返回删除的元素数
  std::erase(v, 3);

  for (auto i : v) {
    std::cout << i << ' ';
  }
  std::cout << '\n';

  std::erase_if(v, [](auto i) { return i % 2 == 0; });

  for (auto i : v) {
    std::cout << i << ' ';
  }
  std::cout << '\n';
}
