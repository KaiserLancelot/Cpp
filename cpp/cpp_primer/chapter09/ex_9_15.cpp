//
// Created by kaiser on 18-12-5.
//

#include <cstdint>
#include <iostream>
#include <vector>

int main()
{
    std::vector<std::int32_t> vi1{1, 2, 3};
    std::vector<std::int32_t> vi2{1, 2, 3, 4};
    std::cout << (vi1 == vi2 ? "equal" : "not equal") << '\n';
}
