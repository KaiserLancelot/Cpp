//
// Created by kaiser on 18-12-18.
//

#include <unordered_map>
#include <string>
#include <iostream>
#include <cstdint>

int main() {
    std::unordered_map<std::string, std::int32_t> word_count;
    std::string word;
    while (std::cin >> word) {
        auto[iter, check]{word_count.emplace(word, 1)};
        if (!check) {
            ++iter->second;
        }
    }

    for (const auto &[s, count]:word_count) {
        std::cout << s << ' ' << count << '\n';
    }
}