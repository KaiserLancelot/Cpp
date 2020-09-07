//
// Created by kaiser on 18-12-19.
//

#include <fstream>
#include <iostream>
#include <string>

#include "ex_12_19.h"

int main()
{
    std::ifstream ifs{"book"};
    std::string line;
    StrBlob sb;

    while (std::getline(ifs, line)) {
        sb.push_back(line);
    }

    for (auto begin{std::begin(sb)}; begin.not_equal(std::end(sb));
         begin.incr()) {
        std::cout << begin.deref() << '\n';
    }
}
