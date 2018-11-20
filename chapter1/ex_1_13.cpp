//
// Created by kaiser on 18-11-20.
//

#include <iostream>

int main()
{
    //ex 1.9
    int sum = 0;

    for (int val = 50; val <= 100; ++val)
        sum += val;

    std::cout << sum << '\n';

    //ex 1.10
    for (int val = 10; val >= 0; --val)
        std::cout << val << ' ';
    std::cout << '\n';

    //ex1.11
    int v1, v2;
    std::cin >> v1 >> v2;

    for (; v1 <= v2; ++v1)
        std::cout << v1 << ' ';
    std::cout << '\n';
}