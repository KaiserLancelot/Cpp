//
// Created by kaiser on 18-12-19.
//

#include <iostream>
#include <vector>
#include <cstdint>
#include <iterator>
#include <algorithm>
#include <memory>

std::shared_ptr<std::vector<std::int32_t>> MakeVec() {
    return std::make_shared<std::vector<std::int32_t>>();
}

void ReadVec(const std::shared_ptr<std::vector<std::int32_t>> &vec) {
    vec->assign(std::istream_iterator<std::int32_t>{std::cin}, {});
}

void PrintVec(const std::shared_ptr<std::vector<std::int32_t>> &vec) {
    std::copy(std::begin(*vec), std::end(*vec),
              std::ostream_iterator<std::int32_t>{std::cout, " "});
}

int main() {
    auto vec{MakeVec()};
    ReadVec(vec);
    PrintVec(vec);
    std::cout << '\n';
}