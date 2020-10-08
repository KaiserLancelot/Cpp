#include <cstdint>
#include <iostream>

int main() {
  std::uint32_t u{10};
  std::uint32_t u2{42};
  std::cout << u2 - u << '\n';
  std::cout << u - u2 << '\n';

  std::int32_t i{10};
  std::int32_t i2{42};
  std::cout << i2 - i << '\n';
  std::cout << i - i2 << '\n';
  std::cout << i - u << '\n';
  std::cout << u - i << '\n';
}
