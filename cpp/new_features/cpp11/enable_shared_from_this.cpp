//
// Created by kaiser on 19-3-15.
//

#include <iostream>
#include <memory>

// C++11 std::enable_shared_from_this
// 能让其一个对象(假设其名为 t, 且已被一个
// std::shared_ptr 对象 pt 管理)安全地生成其他额外的 std::shared_ptr
// 实例, 它们与 pt 共享对象 t 的所有权。
struct Good : std::enable_shared_from_this<Good> {
  std::shared_ptr<Good> get_ptr() { return shared_from_this(); }
};

struct Bad {
  // 错误写法：用不安全的表达式试图获得 this 的 shared_ptr 对象
  std::shared_ptr<Bad> get_ptr() { return std::shared_ptr<Bad>(this); }
  ~Bad() { std::cout << "Bad::~Bad() called\n"; }
};

int main() {
  // 正确的示例：两个 shared_ptr 对象将会共享同一对象
  auto gp1{std::make_shared<Good>()};
  auto gp2{gp1->get_ptr()};
  std::cout << "gp2.use_count() = " << gp2.use_count() << '\n';

  // 错误的使用示例:调用 shared_from_this 但其没有被 std::shared_ptr 占有
  try {
    Good not_so_good;
    auto gp1{not_so_good.get_ptr()};
  } catch (std::bad_weak_ptr &e) {
    // C++17 起抛出 std::bad_weak_ptr 异常
    std::cout << e.what() << '\n';
  }

  // 错误的示例, 每个 shared_ptr 都认为自己是对象仅有的所有者
  auto bp1{std::make_shared<Bad>()};
  std::cout << bp1.use_count() << '\n';
  auto bp2{bp1->get_ptr()};
  std::cout << bp2.use_count() << '\n';
  // 注意 bp2 会 delete this
}
