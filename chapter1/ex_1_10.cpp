//
// Created by kaiser on 18-11-20.
//

#include <iostream>

int main()
{
    int val = 10;

    while (val >= 0)
    {
        std::cout << val << ' ';
        --val;
    }
    std::cout << '\n';
}