//
// Created by kaiser on 2020/4/27.
//

// TODO Learn asio

#include <iostream>

#include <boost/asio/deadline_timer.hpp>
#include <boost/asio/io_context.hpp>
#include <boost/date_time/posix_time/posix_time_duration.hpp>

int main() {
  boost::asio::io_context ioc;
  boost::asio::deadline_timer timer{ioc, boost::posix_time::seconds(1)};

  timer.async_wait([](auto) { std::cout << "Hello, world!\n"; });
  ioc.run();
}
