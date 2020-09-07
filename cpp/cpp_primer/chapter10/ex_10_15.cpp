//
// Created by kaiser on 18-12-17.
//

#include <cstdint>
#include <iostream>

int main()
{
    std::int32_t i{2};
    std::cout << [i](auto a) { return a + i; }(5) << '\n';
}
