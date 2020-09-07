//
// Created by kaiser on 18-12-3.
//

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::ifstream ifs{"book"};

    if (!ifs) {
        std::cerr << "can't open file\n";
        return EXIT_FAILURE;
    }

    std::string line;
    std::vector<std::string> vs;

    while (std::getline(ifs, line)) {
        vs.push_back(line);
    }

    for (const auto& s : vs) {
        std::cout << s << '\n';
    }
}
