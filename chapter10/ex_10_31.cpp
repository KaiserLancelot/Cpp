//
// Created by kaiser on 18-12-17.
//

#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <iterator>

int main() {
    std::vector<std::int32_t> vi(std::istream_iterator<std::int32_t>{std::cin}, {});
    std::sort(std::begin(vi), std::end(vi));
    std::unique_copy(std::begin(vi), std::end(vi), std::ostream_iterator<std::int32_t>{std::cout, " "});
    std::cout << '\n';
}