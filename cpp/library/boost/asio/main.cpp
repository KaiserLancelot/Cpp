//
// Created by kaiser on 2020/4/27.
//

// TODO Learn asio

#include <chrono>
#include <iostream>
#include <system_error>

#include <boost/asio/io_context.hpp>
#include <boost/asio/steady_timer.hpp>

int main()
{
    using namespace std::chrono_literals;

    boost::asio::io_context ioc{1};
    boost::asio::steady_timer timer{ioc, 500ms};

    timer.async_wait([](std::error_code error) {
        if (error) {
            std::cerr << error.message() << '\n';
        }
        else {
            std::cout << "Hello, world!\n";
        }
    });

    ioc.run();
}
