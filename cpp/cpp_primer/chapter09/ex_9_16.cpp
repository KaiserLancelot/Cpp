//
// Created by kaiser on 18-12-5.
//

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <list>
#include <vector>

int main()
{
    std::vector<std::int32_t> vi1{1, 2, 3};
    std::vector<std::int32_t> vi2{1, 2, 3, 4};

    std::cout << (std::equal(std::cbegin(vi1), std::cend(vi1), std::cbegin(vi2),
                             std::cend(vi2))
                          ? "equal"
                          : "not equal")
              << '\n';
}
