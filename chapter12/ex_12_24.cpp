//
// Created by kaiser on 18-12-19.
//

#include <iostream>
#include <memory>
#include <cstddef>

int main() {
    constexpr std::size_t size{10};
    auto s{std::make_unique<char[]>(size)};

    for (std::size_t i{}; i + 1 < size; ++i) {
        s[i] = static_cast<char>(std::cin.get());
    }

    std::cout << s.get() << '\n';
}