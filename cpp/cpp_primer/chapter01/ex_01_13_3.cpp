#include <cstdint>
#include <iostream>

int main() {
  std::int32_t v1;
  std::int32_t v2;
  std::cin >> v1 >> v2;

  for (; v1 <= v2; ++v1) {
    std::cout << v1 << ' ';
  }
  std::cout << '\n';
}
