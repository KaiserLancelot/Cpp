//
// Created by kaiser on 19-3-4.
//

#include <cstdint>
#include <iostream>
#include <vector>

template <typename T>
void Print(const T& t) {
  for (auto iter{std::begin(t)}; iter != std::end(t); ++iter) {
    std::cout << *iter << '\n';
  }
}

int main() {
  std::vector<std::int32_t> v{1, 2, 3, 4};
  Print(v);
}