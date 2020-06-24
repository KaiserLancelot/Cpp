//
// Created by kaiser on 20-4-25.
//

// lhs <=> rhs 表达式返回一个对象, 使得
// 若 lhs < rhs 则 (a <=> b) < 0
// 若 lhs > rhs 则 (a <=> b) > 0
// 若 lhs 和 rhs 相等/等价则 (a <=> b) == 0

// 若操作数之一为 bool 类型而另一个不是, 程序非良构

// 若两个操作数均具有算术类型, 或若一个具有无作用域枚举类型而
// 另一个具有整型类型, 则对各操作数应用一般算术转换, 然后
// 若需要进行除了从整型类型到浮点类型之外的窄化转换, 则程序非良构
// 否则, 若各操作数均具有整型类型
// 若两个操作数算术上相等则为 std::strong_ordering::equal
// 若第一操作数算术上小于第二个则为 std::strong_ordering::less
// 否则为 std::strong_ordering::greater。
// 否则, 操作数均具有浮点类型
// 若 a 小于 b 则为 std::partial_ordering::less
// 若 a 大于 b 则为 std::partial_ordering::greater
// 若 a 等价于 b 则为 std::partial_ordering::equivalent(-0 <=> +0 为等价)
// 否则为 std::partial_ordering::unordered(NaN <=> 任何值 为无序)

// 若两个操作数都具有相同的枚举类型 E, 则运算符产出将各操作数转换
// 为 E 的底层类型再对转换后的操作数应用 <=> 的结果

// 若至少一个操作数为指针或成员指针, 则按需应用数组到指针转换
// 派生类到基类指针转换, 函数指针转换和限定性转换
// 以将它们转换为同一指针类型, 且结果指针类型为对象指针类型
// 若 p == q 则为 std::strong_ordering::equal
// 若 q > p 则为 std::strong_ordering::less
// 若 p > q 则为 std::strong_ordering::greater
// 若未指明这些指针值的比较(例如它们不指向
// 同一对象或数组之中时), 则为未指明的结果

// 否则程序非良构
int main() {
  unsigned int i = 1;
  // auto r = -1 < i;  // 既存陷阱: 返回 false
  // auto r2 = -1 <=> i;  // 错误: 要求窄化转换
  (void)i;
}
