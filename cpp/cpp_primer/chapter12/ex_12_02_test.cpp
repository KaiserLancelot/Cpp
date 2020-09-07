//
// Created by kaiser on 18-12-19.
//

#include "ex_12_02.h"

#include <iostream>

int main()
{
    const StrBlob csb{"hello", "world", "AAA"};
    StrBlob sb{"hello", "world", "BBB"};

    std::cout << csb.front() << " " << csb.back() << '\n';
    sb.back() = "AAA";
    std::cout << sb.front() << " " << sb.back() << '\n';
}
