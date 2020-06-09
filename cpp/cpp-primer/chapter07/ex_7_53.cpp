/**
 * @ Author: KaiserLancelot
 * @ Create Time: 2020-05-14 06:33:45
 * @ Modified time: 2020-05-19 03:45:31
 */

#include <array>
#include <cstddef>

#include "ex_7_53.h"

int main() {
  constexpr Debug k_debug{true, true, true};
  std::array<double, static_cast<std::size_t>(k_debug.any())> array;
  (void)array;
}
