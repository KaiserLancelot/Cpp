//
// Created by kaiser on 2020/4/27.
//

// TODO Learn asio

#include <chrono>
#include <iostream>

#include <asio.hpp>

int main()
{
    using namespace std::chrono_literals;

    asio::io_context ioc{1};
    asio::steady_timer timer{ioc, 1s};

    timer.async_wait([](asio::error_code error) {
        if (error) {
            std::cerr << error.message() << '\n';
        }
        else {
            std::cout << "Hello, world!\n";
        }
    });

    ioc.run();
}
