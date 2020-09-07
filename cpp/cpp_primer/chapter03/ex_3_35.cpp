//
// Created by kaiser on 20-4-22.
//

#include <cstdint>
#include <iostream>

int main()
{
    std::int32_t arr[10];

    for (std::size_t i = 0; i < 10; ++i) {
        *(arr + i) = 0;
    }

    for (const auto& item : arr) {
        std::cout << item << ' ';
    }

    std::cout << '\n';
}
