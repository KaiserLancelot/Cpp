//
// Created by kaiser on 19-3-21.
//

#include <iostream>
#include <string_view>

// C++17 std::string_view
// 不持有字符串, 与构造它的字符串共享空间, 只读
// 如果构造它的字符串被销毁了就失效了
// 当不需要改变字符串时应该使用它
int main() {
  // 注意 需要以空字符结尾
  char s[]{"aaa"};
  std::string_view ss{s};
  std::cout << ss << '\n'; // aaa
  s[2] = 'b';
  std::cout << ss << '\n'; // aab

  // 可以由 C风格字符串, 以空字符结尾的字符数组, std::string, std::string_view
  // 构造, 并可以指定大小, 大部分用法与 std::string 一致

  std::string_view sv{"12345678"};
  // 从前面缩减两个字符
  sv.remove_prefix(2);
  std::cout << sv << '\n';
  // 从后面缩减两个字符
  sv.remove_suffix(2);
  std::cout << sv << '\n';
}
