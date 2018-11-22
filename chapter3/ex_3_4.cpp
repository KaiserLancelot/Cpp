//
// Created by kaiser on 18-11-22.
//

#include <iostream>
#include <string>

int main()
{
    std::string word1, word2;
    std::cin >> word1 >> word2;

    //a
    if (word1 == word2)
        std::cout << "equal\n";
    else
        std::cout << (word1 < word2 ? word2 : word1) << '\n';

    //b
    if (std::size(word1) == std::size(word2))
        std::cout << "equal\n";
    else
        std::cout << (std::size(word1) < std::size(word2) ? word2 : word1) << '\n';
}