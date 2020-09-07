//
// Created by kaiser on 20-4-22.
//

#include <cstddef>
#include <cstring>
#include <iostream>
#include <iterator>

int main()
{
    const char s1[] = "aaa";
    const char s2[] = "bbb";

    constexpr std::size_t size{std::size(s1) + std::size(s2) - 1};
    char s[size];

    std::strcpy(s, s1);
    std::strcat(s, s2);

    std::cout << s << '\n';
}
