//
// Created by kaiser on 19-3-6.
//

#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

template <typename T>
std::int32_t Count(const std::vector<T>& vec, const T& val) {
  std::int32_t count{};
  for (const auto& item : vec) {
    if (item == val) {
      ++count;
    }
  }
  return count;
}

int main() {
  std::vector<double> vd{1.1, 1.1, 2.3, 4};
  std::cout << Count(vd, 1.1) << '\n';
}
