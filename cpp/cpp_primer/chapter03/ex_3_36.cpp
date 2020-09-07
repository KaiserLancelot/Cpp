//
// Created by kaiser on 20-4-22.
//

#include <cstdint>
#include <iostream>
#include <vector>

auto array_is_equal(auto&& lhs, auto&& rhs)
{
    if (std::size(lhs) != std::size(rhs)) {
        return false;
    }

    for (std::size_t i = 0; i != std::size(lhs); ++i) {
        if (lhs[i] != rhs[i]) {
            return false;
        }
    }

    return true;
}

int main()
{
    std::int32_t arr[10] = {1, 2, 3};
    std::int32_t arr2[3] = {3, 4, 5};
    std::int32_t arr3[3] = {3, 4, 5};

    std::cout << std::boolalpha << array_is_equal(arr, arr2) << '\n';
    std::cout << array_is_equal(arr2, arr3) << '\n';

    std::vector<std::int32_t> v{1, 2, 3, 0, 0, 0, 0, 0, 0, 0};
    std::vector<std::int32_t> v2{3, 4, 5};
    std::vector<std::int32_t> v3{3, 4, 5};

    std::cout << (v == v2) << '\n';
    std::cout << (v2 == v3) << '\n';
}
