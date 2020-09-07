//
// Created by kaiser on 19-3-11.
//

#include <iostream>
#include <regex>
#include <string>

int main()
{
    std::regex r{R"(\d{5}[-]?\d{4})"};
    std::string s;
    while (std::cin >> s) {
        if (std::regex_match(s, r)) {
            std::cout << "ok\n";
        }
        else {
            std::cout << "not ok\n";
        }
    }
}
