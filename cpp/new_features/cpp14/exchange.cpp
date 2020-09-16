//
// Created by kaiser on 19-3-8.
//

#include <utility>

struct S {
  int* p;
  int n;

  // C++14 std::exchange 定义于 utility
  S(S&& other)
  noexcept : p{std::exchange(other.p, nullptr)}, n{std::exchange(other.n, 0)} {}

  S& operator=(S&& other) noexcept {
    p = std::exchange(other.p,
                      nullptr);  // 移动 p ,同时留 nullptr 于 other.p 中
    n = std::exchange(other.n, 0);  // 移动 n ,同时留零于 other.n 中
    return *this;
  }
};

int main() {}
