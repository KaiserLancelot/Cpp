//
// Created by kaiser on 18-12-19.
//

#include <cstdint>
#include <iostream>
#include <memory>
#include <string>

class Destination {
 public:
  Destination(const std::string &ip, std::int32_t port) : ip{ip}, port{port} {}
  std::string ip;
  std::int32_t port;
};

class Connection {
 public:
  Connection(const std::string &ip, std::int32_t port) : ip{ip}, port{port} {}
  std::string ip;
  std::int32_t port;
};

Connection connect(Destination *dest) {
  return Connection{dest->ip, dest->port};
}

void disconnect(const Connection &conn) {
  std::cout << "connection close(" << conn.ip << ":" << conn.port << ")"
            << std::endl;
}

void f(Destination &d) {
  auto conn{connect(&d)};
  std::shared_ptr<Connection> p{&conn, [](auto p) { disconnect(*p); }};
  std::cout << "connecting now(" << p.use_count() << ")" << std::endl;
}

int main() {
  Destination dest("111.111.111.111", 3316);
  f(dest);
}
