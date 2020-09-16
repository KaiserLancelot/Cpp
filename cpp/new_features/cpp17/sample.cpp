//
// Created by kaiser on 19-3-21.
//

#include <algorithm>
#include <iostream>
#include <iterator>
#include <random>
#include <vector>

int main() {
  std::vector<std::string> vs{"a", "b", "c"};
  std::default_random_engine e{std::random_device{}()};
  // C++17 std::sample
  // 从序列中选择 n 个元素, 使得每个元素拥有相等的出现概率,
  // 并写入这些元素到输出迭代器 用随机数生成器 g 生成随机数.若 n
  // 大于序列中的元素数量, 则选择 end-begin 个元素
  std::sample(std::begin(vs), std::end(vs),
              std::ostream_iterator<std::string>{std::cout, " "}, 2, e);
}
