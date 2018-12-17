//
// Created by kaiser on 18-12-17.
//

#include <vector>
#include <cstdint>
#include <numeric>
#include <iostream>

int main() {
    std::vector<std::int32_t> nums{1, 2, 3};
    std::cout << std::accumulate(std::cbegin(nums), std::cend(nums), 0) << '\n';
}