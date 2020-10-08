#include <cstdint>
#include <iostream>

int main() {
  for (std::int32_t val{10}; val >= 0; --val) {
    std::cout << val << ' ';
  }
  std::cout << '\n';
}
