//
// Created by kaiser on 18-11-20.
//

#include <cstdint>
#include <iostream>

int main()
{
    std::int32_t sum{}, val{50};

    while (val <= 100)
    {
        sum += val;
        ++val;
    }
    std::cout << sum << '\n';
}