/**
 * @ Author: KaiserLancelot
 * @ Create Time: 2020-05-16 07:33:22
 * @ Modified time: 2020-05-19 04:30:52
 */

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <ranges>
#include <span>
#include <vector>

// 类模板 span 所描述的对象能指代对象的相接序列, 序列的首元素在零位置
// span 能拥有静态长度, 该情况下序列中的元素数已知并编码于类型中, 或拥有动态长度
// 典型实现只保有二个成员: 指向 T 的指针和大小

void fun(std::span<std::int32_t> span)
{
    std::cout << span.front() << '\n';
    std::cout << span.back() << '\n';
    std::cout << span[2] << '\n';

    // 获得子段
    std::ranges::sort(span.subspan(0, 3));
    // span.first(3) 前 N 个元素组成的子段
    // span.last(3)
}

int main()
{
    std::vector<std::int32_t> v{11, 2, 1, 434, 22, 3};
    fun(v);

    for (auto i : v) {
        std::cout << i << ' ';
    }
    std::cout << '\n';
}
