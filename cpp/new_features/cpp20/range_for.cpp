//
// Created by kaiser on 2020/4/18.
//

#include <cstdint>
#include <iostream>
#include <vector>

int main()
{
    // 若范围表达式返回临时量, 则其生存期被延续到循环结尾
    // 但要注意范围表达式中任何临时量生存期都不被延长
    // for (auto& x: foo().items()) { /* .. */ } 若 foo() 返回右值则为未定义行为
    // 此问题可用初始化语句变通解决
    // for (T thing = foo(); auto& x :thing.items()) { /* ...*/ } // OK
    for (std::vector<std::int32_t> v{1, 2, 3}; auto i : v) {
        std::cout << i << '\n';
    }
}
