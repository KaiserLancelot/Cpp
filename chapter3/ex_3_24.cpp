//
// Created by kaiser on 18-11-22.
//

#include <iostream>
#include <vector>
#include <cstdint>

int main()
{
    std::vector<std::int32_t> vi;
    std::int32_t value;

    while (std::cin >> value)
        vi.push_back(value);

    if (std::size(vi) == 1)
    {
        std::cout << "only one integer" << '\n';
        return -1;
    }

    //a
    for (auto it{std::begin(vi)}; it + 1 != std::end(vi); ++it)
        std::cout << *it + *(it + 1) << '\n';

    //b
    for (auto lit{std::begin(vi)}, rit{std::end(vi) - 1}; lit != rit; ++lit, --rit)
        std::cout << *lit + *rit << '\n';
}