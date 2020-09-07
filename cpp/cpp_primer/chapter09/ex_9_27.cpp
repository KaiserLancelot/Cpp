//
// Created by kaiser on 18-12-5.
//

#include <cstdint>
#include <forward_list>
#include <iostream>

int main()
{
    std::forward_list<std::int32_t> forward_list{1, 2, 3, 4, 5};

    for (auto cur{std::begin(forward_list)}, prv{forward_list.before_begin()};
         cur != std::end(forward_list);) {
        if (*cur % 2) {
            cur = forward_list.erase_after(prv);
        }
        else {
            prv = cur;
            ++cur;
        }
    }

    for (auto ele : forward_list) {
        std::cout << ele << '\n';
    }
}
