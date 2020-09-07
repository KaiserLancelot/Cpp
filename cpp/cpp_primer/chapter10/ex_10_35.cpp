//
// Created by kaiser on 18-12-17.
//

#include <cstdint>
#include <iostream>
#include <vector>

int main()
{
    std::vector<std::int32_t> vi{1, 2, 3};

    for (auto end{std::end(vi)}; end != std::begin(vi);) {
        std::cout << *--end << '\n';
    }
}
