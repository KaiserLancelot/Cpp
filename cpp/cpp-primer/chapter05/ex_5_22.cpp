//
// Created by kaiser on 20-4-26.
//

#include <cstdint>

std::int32_t get_size() { return 4; }

int main() {
  std::int32_t sz{get_size()};

  for (; sz <= 0; sz = get_size()) {
  }
}
