//
// Created by kaiser on 18-12-17.
//

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

int main()
{
    std::vector<std::int32_t> vi{1, 2, 3, 3, 4, 4, 5};
    std::cout << std::count(std::cbegin(vi), std::cend(vi), 3) << '\n';
}
