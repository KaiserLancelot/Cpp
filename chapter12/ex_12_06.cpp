//
// Created by kaiser on 18-12-19.
//

#include <iostream>
#include <vector>
#include <cstdint>
#include <iterator>
#include <algorithm>

std::vector<std::int32_t> *MakeVec() {
    return new std::vector<std::int32_t>;
}

void ReadVec(std::vector<std::int32_t> *vec) {
    vec->assign(std::istream_iterator<std::int32_t>{std::cin}, {});
}

void PrintVec(std::vector<std::int32_t> *vec) {
    std::copy(std::begin(*vec), std::end(*vec),
              std::ostream_iterator<std::int32_t>{std::cout, " "});
}

int main() {
    auto vec{MakeVec()};
    ReadVec(vec);
    PrintVec(vec);
    std::cout << '\n';
    delete vec;
}