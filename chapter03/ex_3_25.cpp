//
// Created by kaiser on 18-11-22.
//

#include <iostream>
#include <vector>

int main() {
    std::vector<std::int32_t> scores(11, 0);
    std::int32_t grade;

    while (std::cin >> grade) {
        if (grade <= 100 && grade >= 0)
            ++*(std::begin(scores) + grade / 10);
    }
}