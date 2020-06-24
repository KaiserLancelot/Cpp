//
// Created by kaiser on 18-12-19.
//

#include <cstring>
#include <iostream>
#include <memory>

int main() {
  const char *s1{"hello"};
  const char *s2{"world"};

  auto size{std::strlen(s1) + std::strlen(s2) + 1};
  auto s{std::make_unique<char[]>(size)};

  std::strcpy(s.get(), s1);
  std::strcpy(s.get() + std::strlen(s1), s2);

  std::cout << s.get() << '\n';
}
