//
// Created by kaiser on 19-3-10.
//

#include <iostream>
#include <string>
#include <tuple>

class A {
public:
    A(const std::string& s1, const std::string& s2) : s1_{s1}, s2_{s2} {};
    void show() const { std::cout << s1_ << ' ' << s2_ << '\n'; }

private:
    std::string s1_;
    std::string s2_;
};

int main()
{
    std::tuple<std::string, std::string> tuple{"aaa", "bbb"};
    // C++17 std::make_from_tuple 定义于 tuple,构造 T 类型对象,以元组 t
    // 的元素为构造函数的参数
    auto a{std::make_from_tuple<A>(tuple)};
    a.show();
}
