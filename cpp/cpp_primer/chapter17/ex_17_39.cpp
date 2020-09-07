//
// Created by kaiser on 19-3-13.
//

#include <cstddef>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

int main()
{
    std::fstream in_out{"copy_out",
                        std::fstream::ate | std::fstream::in | std::fstream::out};

    if (!in_out) {
        std::cerr << "Unable to open file!\n";
        return EXIT_FAILURE;
    }

    auto end_mark{in_out.tellg()};
    in_out.seekg(0, std::fstream::beg);
    std::size_t cnt{};
    std::string line;

    while (in_out && in_out.tellg() < end_mark && std::getline(in_out, line)) {
        cnt += std::size(line) + 1;
        auto mark{in_out.tellg()};
        in_out.seekp(0, std::fstream::end);
        in_out << cnt;
        if (mark != end_mark) {
            in_out << ' ';
        }
        in_out.seekg(mark);
    }
    in_out.seekp(0, std::fstream::end);
    in_out << '\n';
}
