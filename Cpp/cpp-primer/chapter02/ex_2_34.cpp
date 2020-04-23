//
// Created by kaiser on 2020/4/17.
//

#include <cstdint>
#include <iostream>

int main() {
  std::int32_t i = 0, &r = i;
  auto a = r;

  const std::int32_t kCi = i, &cr = kCi;
  auto b = kCi;
  auto c = cr;
  auto d = &i;
  auto e = &kCi;

  const auto kF = kCi;
  auto &g = kCi;

  (void)d;
  (void)e;
  (void)kF;
  (void)g;

  a = 42;
  b = 42;
  c = 42;
  //  d = 42;
  //  e = 42;
  //  g = 42;

  std::cout << a << '\n';
  std::cout << b << '\n';
  std::cout << c << '\n';
}
