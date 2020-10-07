#include <cstdint>
#include <iostream>

int main() {
  std::int32_t sum{};
  std::int32_t val{50};

  while (val <= 100) {
    sum += val;
    ++val;
  }
  std::cout << sum << '\n';
}
