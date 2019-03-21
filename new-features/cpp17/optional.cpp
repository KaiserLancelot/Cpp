//
// Created by kaiser on 19-3-21.
//

#include <cstdint>
#include <iostream>
#include <optional>

// C++17 std::optional

std::optional<std::int32_t> ReadInt() {
  std::int32_t i;
  if (std::cin >> i) {
    return i;
  } else {
    return {};
  }
}

std::optional<std::int32_t> operator+(std::optional<std::int32_t> a,
                                      std::optional<std::int32_t> b) {
  // 同 a.has_value()
  if (!a || !b) {
    return {};
  } else {
    // 同 a.value()
    return *a + *b;
  }
}

int main() {
  auto a{ReadInt()};
  auto b{ReadInt()};

  auto sum{a + b};
  if (sum) {
    std::cout << *sum << '\n';
  } else {
    std::cerr << "error\n";
  }
  // optional::value_or
  // 失败时使用默认值返回
  // 失败时访问会抛出 std::logic_error 异常
}