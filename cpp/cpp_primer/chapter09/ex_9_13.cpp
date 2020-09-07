//
// Created by kaiser on 18-12-5.
//

#include <cstdint>
#include <iostream>
#include <list>
#include <vector>

int main()
{
    std::list<std::int32_t> li{1, 2, 3};
    std::vector<double> vd1{std::cbegin(li), std::cend(li)};
    for (auto ele : vd1) {
        std::cout << ele << ' ';
    }
    std::cout << '\n';

    std::vector<std::int32_t> vi{1, 2, 3, 4};
    std::vector<double> vd2{std::cbegin(vi), std::cend(vi)};
    for (auto ele : vd2) {
        std::cout << ele << ' ';
    }
    std::cout << '\n';
}
