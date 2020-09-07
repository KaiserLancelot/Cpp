//
// Created by kaiser on 20-4-22.
//

#include <compare>
#include <cstring>
#include <iostream>
#include <string>

int main()
{
    std::string str1{"aaa"}, str2{"bbb"};
    if ((str1 <=> str2) == std::strong_ordering::less) {
        std::cout << "less\n";
    }

    const char *s1 = "aaa", *s2 = "bbb";
    if (std::strcmp(s1, s2) < 0) {
        std::cout << "less\n";
    }
}
