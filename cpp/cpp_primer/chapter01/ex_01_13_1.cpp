#include <cstdint>
#include <iostream>

int main() {
  std::int32_t sum{};

  for (std::int32_t val{50}; val <= 100; ++val) {
    sum += val;
  }

  std::cout << sum << '\n';
}
