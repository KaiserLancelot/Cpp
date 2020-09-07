//
// Created by kaiser on 18-12-19.
//

#include <iostream>

#include "ex_12_22.h"

int main()
{
    const StrBlob sb{"a", "b", "c"};

    for (auto begin{std::begin(sb)}; begin.not_equal(std::end(sb));
         begin.incr()) {
        std::cout << begin.deref() << '\n';
    }
}
