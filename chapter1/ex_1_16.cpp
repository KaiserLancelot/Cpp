//
// Created by kaiser on 18-11-20.
//

#include <iostream>

int main()
{
    int sum = 0, val;

    while (std::cin >> val)
        sum += val;

    std::cout << sum << '\n';
}