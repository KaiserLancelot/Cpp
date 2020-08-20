//
// Created by kaiser on 19-3-12.
//

#include <string>

// 在 header-only 模式下, 包含 fmt/format.h 而不是 fmt/core.h
#include <fmt/format.h>

int main() {
  // 返回格式化后的字符串
  std::string message{fmt::format("The answer is {}", 42)};
  // 默认将格式化数据打印到 stdout, 在格式化字符串之前有一个 std::FILE 类型
  // 参数,可以指定打印到何处
  fmt::print("{}\n", message);
  fmt::print(stderr, "{}\n", message);
}
