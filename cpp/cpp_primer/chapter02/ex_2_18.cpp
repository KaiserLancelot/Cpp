//
// Created by kaiser on 2020/4/17.
//

#include <cstdint>
#include <iostream>

int main()
{
    std::int32_t i{42};
    std::int32_t* p;

    p = &i;
    *p = 100;

    std::cout << p << '\n';
    std::cout << *p << '\n';
}
