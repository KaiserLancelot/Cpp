//
// Created by kaiser on 18-12-19.
//

#include "ex_12_02.h"

#include <iostream>

int main() {
    const StrBlob csb{"hello", "world", "AAA"};
    StrBlob sb{"hello", "world", "BBB"};

    std::cout << csb.Front() << " " << csb.Back() << '\n';
    sb.Back() = "AAA";
    std::cout << sb.Front() << " " << sb.Back() << '\n';
}