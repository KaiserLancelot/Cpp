//
// Created by kaiser on 18-11-20.
//

#include <iostream>

int main()
{
    int sum = 0, val = 50;

    while (val <= 100)
    {
        sum += val;
        ++val;
    }
    std::cout << sum << '\n';
}