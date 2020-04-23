//
// Created by kaiser on 2020/4/17.
//

#include <cstdint>

int main() {
  const std::int32_t kI = 42;

  auto j = kI;
  const auto &k = kI;
  auto *p = &kI;
  const auto kJ2 = kI, &k2 = kI;

  (void)j;
  (void)k;
  (void)p;
  (void)kJ2;
  (void)k2;
}
