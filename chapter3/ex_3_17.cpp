//
// Created by kaiser on 18-11-22.
//

#include <iostream>
#include <string>
#include <vector>
#include <cctype>

int main()
{
    std::vector <std::string> vs;
    std::string word;

    while (std::cin >> word)
        vs.push_back(word);

    for (auto &element : vs)
    {
        for (auto &c : element)
            c = static_cast<char>(std::toupper(c));
        std::cout << element << '\n';
    }
}