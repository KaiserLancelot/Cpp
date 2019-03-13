//
// Created by kaiser on 19-3-13.
//

#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

#include <fmt/core.h>
#include <fmt/format.h>

int main() {
  // fmt 构造一个编译时格式字符串,默认此宏被禁用以防止名字冲突,
  // 要使用它需要先将 FMT_STRING_ALIAS 定义为 1
  // 如果说明符无效则编译错误
  std::string s(fmt::format(fmt("{:s}"), "foo"));
  fmt::print("{}\n", s);

  std::ostream_iterator<char> it{std::cout, " "};
  fmt::format_to(it, "{}\n", s);

  std::vector<char> v;
  // 至多 n 个字符
  fmt::format_to_n(std::back_inserter(v), 2, "{}\n", s);
  for (auto c : v) {
    fmt::print("{}", c);
  }

  // 返回字符数
  fmt::print("{}\n", fmt::formatted_size("{:s}", "foo"));

  std::string filename("madeup");
  std::ifstream file{filename};
  if (!file) {
    throw fmt::system_error(errno, "cannot open file '{}'", filename);
  }
}