//
// Created by kaiser on 18-11-20.
//

#include <iostream>

int main()
{
    std::int32_t sum{}, val;

    while (std::cin >> val)
        sum += val;

    std::cout << sum << '\n';
}