/**
 * @ Author: KaiserLancelot
 * @ Create Time: 2020-05-14 06:33:45
 * @ Modified time: 2020-05-15 02:16:40
 */

#include <array>
#include <cstddef>

#include "ex_7_53.h"

int main() {
  constexpr Debug kDebug{true, true, true};
  std::array<double, static_cast<std::size_t>(kDebug.Any())> array;
  (void)array;
}
