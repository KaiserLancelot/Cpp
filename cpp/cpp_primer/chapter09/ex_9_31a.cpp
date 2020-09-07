//
// Created by kaiser on 18-12-5.
//

#include <cstdint>
#include <iostream>
#include <list>

int main()
{
    std::list<std::int32_t> data{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto cur{std::begin(data)}; cur != std::end(data);) {
        if (*cur % 2) {
            data.insert(cur, *cur);
            ++cur;
        }
        else {
            cur = data.erase(cur);
        }
    }

    for (auto i : data) {
        std::cout << i << " ";
    }
}
