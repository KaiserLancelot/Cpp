//
// Created by kaiser on 19-3-10.
//

#include <iostream>
#include <regex>
#include <string>

int main()
{
    std::regex error_pattern{"[[:alpha:]]*[^c]ei[[:alpha:]]*", std::regex::icase};
    std::string word;

    while (std::cin >> word) {
        if (std::regex_match(word, error_pattern)) {
            std::cout << "not ok\n";
        }
        else {
            std::cout << "ok\n";
        }
    }
}
