//
// Created by kaiser on 18-12-19.
//

#include <iostream>
#include <string>
#include <memory>
#include <cstdint>

class Destination {
 public:
  Destination(const std::string &ip, std::int32_t port) : ip_{ip}, port_{port} {}
  std::string ip_;
  std::int32_t port_;
};

class Connection {
 public:
  Connection(const std::string &ip, std::int32_t port) : ip_{ip}, port_{port} {}
  std::string ip_;
  std::int32_t port_;
};

Connection Connect(Destination *dest) {
  return Connection{dest->ip_, dest->port_};
}

void Disconnect(Connection conn) {
  std::cout << "connection close(" << conn.ip_ << ":" << conn.port_ << ")" << std::endl;
}

void f(Destination &d) {
  auto conn{Connect(&d)};
  std::shared_ptr<Connection> p{&conn, [](auto p) { Disconnect(*p); }};
  std::cout << "connecting now(" << p.use_count() << ")" << std::endl;
}

int main() {
  Destination dest("111.111.111.111", 3316);
  f(dest);
}