//
// Created by kaiser on 19-3-18.
//

#include <cstdint>
#include <iostream>
#include <vector>

std::int32_t Add(std::int32_t a, std::int32_t b) { return a + b; }
std::int32_t Sub(std::int32_t a, std::int32_t b) { return a - b; }
std::int32_t Mul(std::int32_t a, std::int32_t b) { return a * b; }
std::int32_t Div(std::int32_t a, std::int32_t b) { return a / b; }

int main() {
  using FuncPointer = std::int32_t (*)(std::int32_t, std::int32_t);
  std::vector<FuncPointer> v{Add, Sub, Mul, Div};
  for (const auto &item : v) {
    std::cout << item(2, 3) << '\n';
  }
}