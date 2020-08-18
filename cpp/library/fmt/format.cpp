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
  // FMT_STRING 构造 compile-time 格式化字符串
  std::string s{fmt::format(FMT_STRING("{:s}"), "foo")};
  fmt::print("{}\n", s);

  // 返回字符数
  fmt::print("{}\n", fmt::formatted_size("{}", "foo"));

  std::vector<char> out;
  fmt::format_to(std::back_inserter(out), "{}", 42);

  std::vector<int> v = {1, 2, 3};
  fmt::print("{}", fmt::join(v, ", "));
  std::cout << '\n';

  fmt::memory_buffer buffer;
  fmt::format_to(buffer, "The answer is {}.", 42);
  std::cout << buffer.data() << '\n';
}
