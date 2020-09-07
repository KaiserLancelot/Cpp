//
// Created by kaiser on 18-12-17.
//

#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

int main()
{
    std::ifstream ifs{"str"};
    std::vector<std::string> vs(std::istream_iterator<std::string>{ifs}, {});

    for (const auto& s : vs) {
        std::cout << s << '\n';
    }
}
