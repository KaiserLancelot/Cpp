//
// Created by kaiser on 19-3-13.
//

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

  // 返回字符数
  fmt::print("{}\n", fmt::formatted_size("{}", "foo"));
}