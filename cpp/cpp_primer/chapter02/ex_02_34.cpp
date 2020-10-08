#include <cstdint>
#include <iostream>

int main() {
  std::int32_t i = 0, &r = i;
  auto a = r;

  const std::int32_t k_ci = i, &cr = k_ci;
  auto b = k_ci;
  auto c = cr;
  auto d = &i;
  auto e = &k_ci;

  const auto k_f = k_ci;
  auto& g = k_ci;

  (void)d;
  (void)e;
  (void)k_f;
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
