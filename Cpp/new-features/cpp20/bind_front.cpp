/**
 * @ Author: KaiserLancelot
 * @ Create Time: 2020-05-17 21:25:06
 * @ Modified time: 2020-05-17 21:34:55
 */

#include <cstdint>
#include <functional>
#include <iostream>

std::int32_t Minus(std::int32_t a, std::int32_t b) { return a - b; }

int main() {
  // 不同于 std::bind , 它不支持任意参数重排
  auto fifty_minus{std::bind_front(&Minus, 50)};
  std::cout << fifty_minus(3) << '\n';
}
