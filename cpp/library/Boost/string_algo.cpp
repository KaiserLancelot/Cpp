//
// Created by kaiser on 2020/4/27.
//

#include <iostream>
#include <string>
#include <vector>

#include <boost/algorithm/string.hpp>

int main() {
  std::string str{"string"};

  // 基本都有不带 copy 的版本
  std::cout << boost::to_upper_copy(str) << '\n';
  std::cout << boost::replace_all_copy(str, "str", "111") << '\n';
  std::cout << boost::erase_all_copy(str, "str") << '\n';
  // 删除前几个字符
  std::cout << boost::erase_head_copy(str, 2) << '\n';
  // 删除后几个字符
  std::cout << boost::erase_tail_copy(str, 2) << '\n';
  // 返回前几个字符
  std::cout << boost::find_head(str, 4) << '\n';
  // 返回后几个字符
  std::cout << boost::find_tail(str, 4) << '\n';

  str = "   \nstr\t ";
  std::cout << boost::trim_copy(str) << '\n';
  // 连接字符串
  std::cout << boost::join(std::vector<std::string>{"a", "b", "c"}, "*")
            << '\n';

  str = "aaa|bbb|ccc";
  std::vector<std::string> s;

  for (const auto &string : boost::split(s, str, boost::is_any_of("|"))) {
    std::cout << string << '\n';
  }
  std::cout << std::size(s) << '\n'; // 3

  str = " aaa bbb ccc  ";
  s.clear();

  for (const auto &string : boost::split(s, str, boost::is_space())) {
    std::cout << string << '\n';
  }
  std::cout << std::size(s) << '\n'; // 6
}
