//
// Created by kaiser on 18-12-17.
//

#include <vector>
#include <algorithm>
#include <iterator>
#include <cstdint>
#include <list>
#include <iostream>

int main() {
    std::vector<std::int32_t> vi{1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::list<std::int32_t> li;

    std::copy(std::begin(vi), std::end(vi), std::back_inserter(li));
    for (auto i:li) {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    li.clear();
    std::copy(std::begin(vi), std::end(vi), std::inserter(li, std::begin(li)));
    for (auto i:li) {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    li.clear();
    std::copy(std::begin(vi), std::end(vi), std::front_inserter(li));
    for (auto i:li) {
        std::cout << i << ' ';
    }
    std::cout << '\n';
}