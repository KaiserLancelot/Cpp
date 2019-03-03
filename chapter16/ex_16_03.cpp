//
// Created by kaiser on 18-12-27.
//

#include <cstdint>
#include <functional>
#include <iostream>

class SalesData {};

template <typename T>
constexpr std::int32_t Compare(const T &v1, const T &v2) {
  if (std::less<>{}(v1, v2)) {
    return -1;
  } else if (std::less<>{}(v2, v1)) {
    return 1;
  } else {
    return 0;
  }
}

int main() { std::cout << Compare(SalesData{}, SalesData{}) << '\n'; }