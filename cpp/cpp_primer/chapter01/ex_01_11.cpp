#include <cstdint>
#include <iostream>

int main() {
  std::int32_t v1, v2;
  std::cin >> v1 >> v2;

  while (v1 <= v2) {
    std::cout << v1 << ' ';
    ++v1;
  }
  std::cout << '\n';
}
