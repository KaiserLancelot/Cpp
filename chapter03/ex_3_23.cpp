//
// Created by kaiser on 18-11-22.
//

#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>

int main() {
    std::vector<std::int32_t> vi(10);
    std::iota(std::begin(vi), std::end(vi), 1);

    for (auto it{std::begin(vi)}; it != std::end(vi); ++it) {
        *it *= 2;
        std::cout << *it << ' ';
    }
    std::cout << '\n';
}