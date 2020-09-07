//
// Created by kaiser on 18-12-20.
//

#include "ex_13_26.h"

#include <iostream>

int main()
{
    const StrBlob sb{"a", "b", "c"};

    for (auto begin{sb.begin()}; begin.NotEqual(sb.end()); begin.Incr()) {
        std::cout << begin.Deref() << '\n';
    }
}
