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
        ++word_count[word];
    }

    for (const auto &[s, count]:word_count) {
        std::cout << s << ' ' << count << '\n';
    }
}