//
// Created by kaiser on 18-12-26.
//

#include <cstddef>
#include <fstream>
#include <iostream>

#include "ex_15_42_query.h"

int main()
{
    std::ifstream file{"story"};
    TextQuery text{file};
    std::size_t begin{}, end{};

    std::cin >> begin >> end;

    Query query{~Query("Alice")};
    Print(std::cout, query.Eval(text), begin, end) << '\n';
}
