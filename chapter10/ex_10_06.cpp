//
// Created by kaiser on 18-12-17.
//

#include <vector>
#include <cstdint>
#include <algorithm>
#include <iostream>

int main() {
    std::vector<std::int32_t> vi(10, -1);
    std::fill_n(std::begin(vi), 10, 0);
    for (auto i:vi) {
        std::cout << i << ' ';
    }
    std::cout << '\n';
}