//
// Created by kaiser on 18-11-28.
//

#include <cstdint>
#include <iostream>

std::int32_t Abs(std::int32_t val) {
    return val > 0 ? val : -val;
}

int main() {
    std::cout << Abs(2) << '\n';
    std::cout << Abs(-2) << '\n';
}