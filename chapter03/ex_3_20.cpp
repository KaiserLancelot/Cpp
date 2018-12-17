//
// Created by kaiser on 18-11-22.
//

#include <iostream>
#include <vector>
#include <cstdint>

int main() {
    std::vector<std::int32_t> vi;
    std::int32_t value;

    while (std::cin >> value)
        vi.push_back(value);

    if (std::size(vi) == 1) {
        std::cout << "only one integer" << '\n';
        return -1;
    }

    //a
    for (decltype(std::size(vi)) index{}; index + 1 < std::size(vi); index += 2)
        std::cout << vi[index] + vi[index + 1] << '\n';

    //b
    for (decltype(std::size(vi)) index{}; index < std::size(vi) / 2; ++index)
        std::cout << vi[index] + vi[std::size(vi) - index - 1] << '\n';
}