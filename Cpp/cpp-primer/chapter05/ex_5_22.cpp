//
// Created by kaiser on 20-4-26.
//

#include <cstdint>

std::int32_t GetSize() { return 4; }

int main() {
  std::int32_t sz{GetSize()};

  for (; sz <= 0; sz = GetSize()) {
  }
}
