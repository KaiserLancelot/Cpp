//
// Created by kaiser on 19-3-24.
//

#include <chrono>
#include <iostream>

#include <experimental/io_context>
#include <experimental/timer>

namespace asio = std::experimental::net;

int main() {
  using namespace std::chrono_literals;
  asio::io_context ioc;
  asio::steady_timer timer{ioc, 1s};
  timer.async_wait([](auto) { std::cout << "Hello, world!\n"; });
  ioc.run();
}