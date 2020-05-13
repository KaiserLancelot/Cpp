/**
 * @ Author: KaiserLancelot
 * @ Create Time: 2020-05-14 06:33:45
 * @ Modified by: KaiserLancelot
 * @ Modified time: 2020-05-14 06:55:46
 */

#include <array>
#include <cstddef>

#include "ex_7_53.h"

int main() {
  constexpr Debug kDebug{true, true, true};
  std::array<double, static_cast<std::size_t>(kDebug.Any())> array;
  (void)array;
}
