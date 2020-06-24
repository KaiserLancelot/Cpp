//
// Created by kaiser on 19-3-19.
//

#include <cstdint>
#include <iostream>
#include <set>
#include <string>
#include <tuple>

struct S {
  std::int32_t n;
  std::string s;
  float d;
  bool operator<(const S &rhs) const {
    // C++11 std::tie
    // 创建到其参数或 std::ignore 实例的左值引用的 tuple
    // std::tie 能用于引入字典序比较到结构体, 或解包 tuple
    // std::tie 可用于解包 std::pair, 因为 std::tuple 拥有从 pair 的转换赋值
    // 比较 n 与 rhs.n,
    // 然后比较 s 与 rhs.s,
    // 然后比较 d 与 rhs.d
    return std::tie(n, s, d) < std::tie(rhs.n, rhs.s, rhs.d);
  }
};

int main() {
  std::set<S> set_of_s; // S 为可比较小于 (LessThanComparable)

  S value{42, "Test", 3.14};
  std::set<S>::iterator iter;
  bool inserted;

  // 解包 insert 的返回值为 iter 与 inserted
  std::tie(iter, inserted) = set_of_s.insert(value);

  if (inserted) {
    std::cout << "Value was inserted successfully\n";
  }
}
