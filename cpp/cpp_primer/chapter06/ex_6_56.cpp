//
// Created by kaiser on 19-3-18.
//

#include <cstdint>
#include <iostream>
#include <vector>

namespace ex {

std::int32_t add(std::int32_t a, std::int32_t b) { return a + b; }
std::int32_t sub(std::int32_t a, std::int32_t b) { return a - b; }
std::int32_t mul(std::int32_t a, std::int32_t b) { return a * b; }
std::int32_t div(std::int32_t a, std::int32_t b) { return a / b; }

}  // namespace ex

int main() {
  using FuncPointer = std::int32_t (*)(std::int32_t, std::int32_t);

  std::vector<FuncPointer> v{ex::add, ex::sub, ex::mul, ex::div};
  for (const auto& item : v) {
    std::cout << item(2, 3) << '\n';
  }
}
