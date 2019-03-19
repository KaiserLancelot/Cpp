//
// Created by kaiser on 19-3-19.
//

// https://stackoverflow.com/questions/43434491/difference-between-if-constexpr-vs-if

#include <cstdint>
#include <iostream>
#include <string>
#include <type_traits>

template <typename T>
constexpr auto length(const T& value) noexcept {
  // C++17 std::is_integral_v
  // 检查 T 是否是整数类型
  // C++17 constexpr-if
  // 在编译时判断, 编译后不存在分支
  // 在被舍去语句中的 return 语句不参与函数返回类型推导
  if constexpr (std::is_integral_v<T>) {
    return value;
  } else {
    return std::size(value);
  }
}

int main() {
  std::int32_t a{42};
  std::string b("foo");
  std::cout << length(a) << '\n' << length(b) << '\n';
  // false
  std::cout << std::boolalpha << std::is_integral_v<int&> << '\n';
}