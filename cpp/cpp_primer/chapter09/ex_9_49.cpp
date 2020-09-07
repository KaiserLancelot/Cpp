//
// Created by kaiser on 18-12-5.
//

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

int main()
{
    std::ifstream ifs{"letter"};
    if (!ifs) {
        std::cerr << "can't open file\n";
        return EXIT_FAILURE;
    }

    std::vector<std::string> vs(std::istream_iterator<std::string>{ifs}, {});
    if (vs.empty()) {
        std::cerr << "no data\n";
        return EXIT_FAILURE;
    }

    std::string longest(vs.front());
    for (const auto& s : vs) {
        if (s.find_first_not_of("aceimnorsuvwxz") == std::string::npos && std::size(s) > std::size(longest)) {
            longest = s;
        }
    }
    std::cout << longest << '\n';
}
