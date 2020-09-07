/**
 * @ Author: KaiserLancelot
 * @ Create Time: 2020-05-16 05:34:51
 * @ Modified time: 2020-05-16 05:36:18
 */

#include <cstdint>
#include <iostream>
#include <vector>

int main()
{
    std::vector<std::int32_t> v;

    std::cout << v.at(0) << '\n';
    std::cout << v.front() << '\n';
    std::cout << *std::begin(v) << '\n';
}
