//
// Created by kaiser on 18-12-5.
//

#include <iostream>
#include <string>

int main() {
    std::string numbers("123456789");
    std::string alpha("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
    std::string str("ab2c3d7R4E6");

    std::string::size_type pos{};
    while ((pos = str.find_first_of(numbers, pos)) != std::string::npos) {
        std::cout << str[pos] << ' ';
        ++pos;
    }
    std::cout << '\n';

    pos = 0;
    while ((pos = str.find_first_of(alpha, pos)) != std::string::npos) {
        std::cout << str[pos] << ' ';
        ++pos;
    }
    std::cout << '\n';
}