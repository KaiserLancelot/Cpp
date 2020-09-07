//
// Created by kaiser on 19-3-14.
//

#include <cstdint>
#include <functional>
#include <iostream>

struct Foo {
    explicit Foo(std::int32_t num) : num{num} {}
    void print_add(std::int32_t i) const { std::cout << num + i << '\n'; }
    std::int32_t num{};
};

void print_num(std::int32_t i) { std::cout << i << '\n'; }

struct PrintNum {
    void operator()(std::int32_t i) const { std::cout << i << '\n'; }
};

int main()
{
    // C++17 std::invoke 定义于 functional
    // 调用自由函数
    std::invoke(print_num, -9);

    // 调用 lambda
    std::invoke([] { print_num(42); });

    // 调用成员函数
    const Foo foo{314159};
    std::invoke(&Foo::print_add, foo, 1);

    // 调用(访问)数据成员
    std::cout << "num_: " << std::invoke(&Foo::num, foo) << '\n';

    // 调用函数对象
    std::invoke(PrintNum{}, 18);
}
