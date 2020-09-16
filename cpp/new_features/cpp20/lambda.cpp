/**
 * @ Author: KaiserLancelot
 * @ Create Time: 2020-05-17 20:54:37
 * @ Modified time: 2020-05-19 04:32:10
 */

#include <cstdint>
#include <iostream>

class A {
 public:
  A(std::int32_t i) : a{i} {}
  std::int32_t fun() {
    // 引用捕获当前对象
    auto f{[this] { return a; }};
    (void)f;
    // 值捕获当前对象(C++17)
    auto f2{[*this] { return a; }};
    (void)f2;

    // 等价于 [&]
    auto f3{[&, this] { return a; }};
    (void)f3;

    // 等价于 [=](C++17)
    auto f4{[=, *this] { return a; }};
    (void)f4;

    // C++20
    auto f5{[=, this] { return a; }};
    (void)f5;

    // 当默认捕获符为 & 时, 能隐式捕获 this
    // 当默认捕获符为 = 时, this 的隐式捕获被弃用(C++20)
    auto f6{[&] { return a; }};
    (void)f6;

    // 错误: this 重复(C++17)
    // [this, *this] {};

    ++a;

    return f5();
  }

  std::int32_t a;
};

int main() {
  std::cout << A{42}.fun() << '\n';

  std::int32_t x{4};
  // 带有初始化器的捕获符, 其行为如同它声明并显示捕获一个以类型 auto 声明的变量
  [&r = x, x = x + 1]() {
    r += 2;
    std::cout << x << '\n';
  }();
  std::cout << x << '\n';
}
