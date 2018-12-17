//
// Created by kaiser on 18-12-17.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool IsShorter(const std::string &s1, const std::string &s2) {
    return std::size(s1) < std::size(s2);
}

void ElimDups(std::vector<std::string> &words) {
    std::sort(std::begin(words), std::end(words));
    words.erase(std::unique(std::begin(words), std::end(words)), std::end(words));
}

int main() {
    std::vector<std::string> vs{"aaaaa", "aaaaa", "cc", "cc", "b"};
    ElimDups(vs);
    std::stable_sort(std::begin(vs), std::end(vs), IsShorter);
    for (const auto &s:vs) {
        std::cout << s << '\n';
    }
}