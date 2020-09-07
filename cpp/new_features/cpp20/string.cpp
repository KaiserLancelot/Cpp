//
// Created by kaiser on 2020/4/18.
//

#include <algorithm>
#include <compare>
#include <iostream>
#include <string>

int main()
{
    // 可以构建 constexpr 的 std::string
    // TODO 编译器尚未支持
    // constexpr std::string s{"string"};

    std::string s{"string"};

    // 检查 string 是否始于给定前/后缀
    std::cout << std::boolalpha << s.starts_with("s") << '\n';
    std::cout << s.ends_with("s") << '\n';

    std::string s2{"str"};
    // 三路比较运算符, 其他的关系运算符已弃用
    // 这里返回的是 std::strong_ordering
    std::cout << ((s <=> s2) == std::strong_ordering::equal) << '\n';
    std::cout << ((s <=> s2) == std::strong_ordering::greater) << '\n';
    // 等价与前者
    std::cout << (std::lexicographical_compare_three_way(
                          std::begin(s), std::end(s), std::begin(s2), std::end(s2))
                  == std::strong_ordering::greater)
              << '\n';
}
