//
// Created by kaiser on 19-3-13.
//

#include <cstdlib>
#include <fstream>
#include <iostream>

int main()
{
    std::ifstream ifs{"story"};
    if (!ifs) {
        std::cerr << "can't open file\n";
        std::exit(EXIT_FAILURE);
    }

    constexpr std::size_t size{60};
    char arr[size]{};

    while (ifs.getline(arr, size, ' ')) {
        std::cout << arr << '\n';
    }
}
