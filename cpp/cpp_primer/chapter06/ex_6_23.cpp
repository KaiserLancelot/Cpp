//
// Created by kaiser on 20-5-5.
//

#include <cassert>
#include <cstdint>
#include <iostream>

void print(const std::int32_t* p)
{
    assert(p != nullptr);
    std::cout << *p << '\n';
}

void print(const std::int32_t* begin, const std::int32_t* end)
{
    assert(begin != nullptr && end != nullptr);

    while (begin != end) {
        std::cout << *begin++ << ' ';
    }
    std::cout << '\n';
}

int main()
{
    std::int32_t i{};
    std::int32_t j[2]{0, 1};

    print(&i);
    print(std::begin(j), std::end(j));
}
