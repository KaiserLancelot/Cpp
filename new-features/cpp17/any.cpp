//
// Created by kaiser on 19-3-21.
//

#include <any>
#include <iostream>
#include <string_view>

// C++17 std::any
// 可以持有任意类型的变量
void Print(const std::any &any) {
  if (!any.has_value()) {
    std::cerr << "nothing\n";
  }

  if (any.type() == typeid(std::string_view)) {
    // 转换不正确抛出 std::bad_any_cast 异常
    // std::any_cast 会返回 any 中转换类型的副本, 可以设置成引用避免拷贝
    std::cout << std::any_cast<std::string_view>(any) << '\n';
  }
}

int main() {
  std::string_view sv{"kaiser"};
  Print(sv);
}