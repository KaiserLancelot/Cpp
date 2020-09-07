//
// Created by kaiser on 19-3-14.
//

#include <cstdlib>
#include <iostream>
#include <stdexcept>

int main()
{
    try {
        throw std::runtime_error{"error"};
    }
    catch (const std::exception& err) {
        std::cerr << err.what() << '\n';
        std::abort();
    }
}
