//
// Created by kaiser on 18-12-23.
//

#include "ex_14_16_string.h"

#include <iostream>

int main()
{
    String s1{"aaa"};
    String s2{"aba"};
    String s3{"aaa"};

    std::cout << std::boolalpha << (s1 == s2) << '\n';
    std::cout << (s1 == s3) << '\n';
}
