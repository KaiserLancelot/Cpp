//
// Created by kaiser on 19-3-19.
//

// https://zh.cppreference.com/w/cpp/language/fold

/*
 * 语法
 *   ( pack op ... )	(1)
 *   ( ... op pack )	(2)
 *   ( pack op ... op init )	(3)
 *   ( init op ... op pack )	(4)
 *     1) 一元右折叠
 *     2) 一元左折叠
 *     3) 二元右折叠
 *     4) 二元左折叠
 *     注意括号是折叠表达式的一部分
 */

/*
 * 折叠表达式的实例化按如下方式展开成表达式 e :
 *
 * 1) 一元右折叠 (E op ...) 成为 (E1 op (... op (EN-1 op EN)))
 * 2) 一元左折叠 (... op E) 成为 (((E1 op E2) op ...) op EN)
 * 3) 二元右折叠 (E op ... op I) 成为 (E1 op (... op (EN−1 op (EN op I))))
 * 4) 二元左折叠 (I op ... op E) 成为 ((((I op E1) op E2) op ...) op EN)
 * （其中 N 是包展开中的元素数）
 */

/*
 * 将一元折叠用于零长包展开时，仅允许下列运算符:
 *
 * 1) 逻辑与( && ).空包的值为 true
 * 2) 逻辑或( || ).空包的值为 false
 * 3) 逗号运算符( , ).空包的值为 void()
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <type_traits>
#include <vector>

template <typename... T>
std::ostream &print(std::ostream &os, const T &... args) {
  return (os << ... << [&args] {
    if constexpr (std::is_array_v<T>) {
      return std::string(args) + ' ';
    } else {
      return std::to_string(args) + ' ';
    }
  }());
}

template <typename T, typename... Args>
auto matches(const T &range, Args... args) {
  return (std::count(std::begin(range), std::end(range), args) + ... + 0);
}

template <typename T, typename... Args>
void push_all(std::vector<T> &v, Args... args) {
  (v.push_back(args), ...);
}

int main() {
  print(std::cout, 1, 3.5, "fuck", -5) << '\n';

  std::cout << matches(std::vector<std::string>{"a", "a", "b", "b"}, "a", "b")
            << '\n';

  std::vector<std::string> v;
  push_all(v, "a", "b", "c");
  for (const auto &item : v) {
    std::cout << item << ' ';
  }
  std::cout << '\n';
}
