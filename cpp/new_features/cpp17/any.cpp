//
// Created by kaiser on 19-3-21.
//

#include <any>
#include <iostream>

int main() {
  std::cout << std::boolalpha;

  // C++17 std::any
  // 用于任何类型的单个值的类型安全容器
  std::any a{1};
  // auto a{std::make_any<int>(1)}; 同上
  // 转换不正确抛出 std::bad_any_cast 异常
  std::cout << a.type().name() << ": " << std::any_cast<int>(a) << '\n';
  a = 3.14;
  std::cout << a.type().name() << ": " << std::any_cast<double>(a) << '\n';
  a = true;
  std::cout << a.type().name() << ": " << std::any_cast<bool>(a) << '\n';

  // 有误的转型
  try {
    a = 1;
    std::cout << std::any_cast<float>(a) << '\n';
  } catch (const std::bad_any_cast &e) {
    std::cout << e.what() << '\n';
  }

  // 拥有值
  a = 1;
  if (a.has_value()) {
    std::cout << a.type().name() << '\n';
  }

  // 重置
  a.reset();
  if (!a.has_value()) {
    std::cout << "no value\n";
  }

  // 指向所含数据的指针
  a = 1;
  int *i = std::any_cast<int>(&a);
  std::cout << *i << "\n";

  // 可以设置为引用避免拷贝
  a = std::string("kaiser");
  std::cout << std::any_cast<std::string &>(a) << '\n';
}
