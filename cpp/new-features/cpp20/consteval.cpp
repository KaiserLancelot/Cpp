//
// Created by kaiser on 2020/5/5.
//

#include <cstdint>

// consteval 说明符声明函数或函数模板为立即函数
// 即该函数的每次潜在求值的调用(即不求值语境外的调用)必须(直接或间接)
// 产生编译时常量表达式.它不可应用于析构函数, 分配函数(allocation)或解分配函数
// consteval 说明符蕴含 inline.同一声明说明符序列中允许出现至多一个
// constexpr, consteval, constinit 说明符.若某个函数或函数模板的任何声明含
// 有 consteval 说明符, 则该函数或函数模板的所有声明必须均含该说明符

// 立即函数是 constexpr 函数, 而且只要情况符合, 必须满足适用于
// constexpr 函数或 constexpr 构造函数的要求
consteval std::int32_t sqr(std::int32_t n) { return n * n; }

consteval std::int32_t sqr_sqr(std::int32_t n) {
  return sqr(sqr(n));  // OK
}

// constexpr std::int32_t DblSqr(std::int32_t n) {
//   return Sqr(Sqr(n));  // 错误: 'n' 不是一个常量表达式
// }

int main() {
  constexpr auto r{sqr(100)};  // OK
  (void)r;
  // std::int32_t x{100};
  // auto r2{Sqr(x)};  // 错误: 调用不产生常量
}
