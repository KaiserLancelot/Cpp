//
// Created by kaiser on 18-12-5.
//

#include <string>
#include <iostream>

void Fun(std::string &s, const std::string &old_val, const std::string &new_val) {
    for (auto begin{std::begin(s)}; begin <= std::end(s) - std::size(old_val);) {
        if (old_val == std::string(begin, begin + std::size(old_val))) {
            begin = s.erase(begin, begin + std::size(old_val));
            begin = s.insert(begin, std::begin(new_val), std::end(new_val));
            begin += std::size(new_val);
        } else {
            ++begin;
        }
    }
}

int main() {
    std::string s("To drive straight thru is a foolish, tho courageous act.");
    Fun(s, "tho", "thought");
    Fun(s, "thru", "through");
    std::cout << s << '\n';
}