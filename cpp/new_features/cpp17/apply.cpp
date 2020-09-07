//
// Created by kaiser on 19-3-10.
//

#include <iostream>
#include <string>
#include <tuple>

void fun(const std::string& s1, const std::string& s2)
{
    std::cout << s1 << ' ' << s2 << '\n';
}

int main()
{
    std::tuple<std::string, std::string> tuple{"aaa", "bbb"};
    // C++17 std::apply 定义于 tuple
    // 用元组 t 的元素调用可调用对象
    std::apply(fun, tuple);
}
