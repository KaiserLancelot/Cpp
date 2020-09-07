//
// Created by kaiser on 18-12-22.
//

#include "ex_13_53.h"

#include <chrono>
#include <iostream>
#include <utility>

int main()
{
    HasPtr hp;
    HasPtr hp1;
    HasPtr hp2;
    const auto t0{std::chrono::system_clock::now()};
    for (int i = 0; i < 100000000; ++i) {
        hp = hp1;
        hp = std::move(hp2);
    }
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(
                         std::chrono::system_clock::now() - t0)
                         .count()
              << " ms\n";
}
