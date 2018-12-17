//
// Created by kaiser on 18-11-27.
//

#include <cstdint>
#include <iostream>
#include <string>
#include <utility>

int main() {
    std::string curr, pre;
    std::pair<std::string, std::int32_t> result;
    std::int32_t count{};

    while (std::cin >> curr) {
        if (curr == pre)
            ++count;
        else
            count = 0;

        if (count > result.second)
            result = {curr, count};
        pre = curr;
    }

    if (result.first.empty())
        std::cout << "No consecutively repeated strings\n";
    else
        std::cout << result.first << ' ' << result.second + 1 << " times\n";
}