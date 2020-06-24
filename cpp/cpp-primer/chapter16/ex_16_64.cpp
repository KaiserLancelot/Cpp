//
// Created by kaiser on 19-3-6.
//

#include <cstdint>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

template <typename T> std::int32_t Count(const std::vector<T> &vec, T val) {
  std::int32_t count{};
  for (const auto &item : vec) {
    if (item == val) {
      ++count;
    }
  }
  return count;
}

template <>
std::int32_t Count(const std::vector<const char *> &vec, const char *val) {
  std::int32_t count{};
  for (const auto &item : vec) {
    if (strcmp(item, val) == 0) {
      ++count;
    }
  }
  return count;
}

int main() {
  std::vector<const char *> vcc = {"alan", "alan", "alan", "alan", "moophy"};
  std::cout << Count(vcc, "alan") << std::endl;
}
