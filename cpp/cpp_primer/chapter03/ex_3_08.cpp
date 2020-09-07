//
// Created by kaiser on 18-11-22.
//

#include <iostream>
#include <string>

int main()
{
    std::string s("hello world");

    // a
    decltype(std::size(s)) index1{};
    while (index1 != std::size(s)) {
        s[index1++] = 'X';
    }
    std::cout << s << '\n';

    // b
    for (decltype(std::size(s)) index2{}; index2 != std::size(s); ++index2) {
        s[index2] = 'X';
    }
    std::cout << s << '\n';
}
