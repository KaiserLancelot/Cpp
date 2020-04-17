#include <bit>
#include <compare>
#include <iostream>
#include <random>
#include <string>
#include <type_traits>
#include <vector>
#include <numbers>

int main() {
  std::popcount(0u);            // 0
  std::popcount(1u);            // 1
  std::popcount(0b1111'0000u);  // 4

  // char8_t c = u8'a';
  // std::cout << c << '\n';

  // char8_t str[] = u8"你好世界";
  // std::cout << str << '\n';

  // std::u8string u8str{str};
  // std::cout << u8str << '\n';

  // std::string s1, s2;
  // s1.push_back(2);
  // //(s1 <=> s2).equivalent;
  // //  (s1 <=> s2);

  // int i = 1;
  // auto r = -1 < i;     // 既存陷阱：返回 false
  // auto r2 = -1 <=> i;  // 错误：要求窄化转换
}
