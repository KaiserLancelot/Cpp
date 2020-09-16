//
// Created by kaiser on 19-3-13.
//

#include <cstddef>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <vector>

template <typename T>
class Array {
 public:
  explicit Array(std::size_t size) : p_{new T[size]} {}
  ~Array() { delete[] p_; }
  T& operator[](std::size_t index) { return p_[index]; }

 private:
  T* p_{};
};

void Exercise(std::int32_t* b, std::int32_t* e) {
  std::vector<std::int32_t> v(b, e);
  // a
  auto p{std::make_unique<std::int32_t[]>(std::size(v))};
  // b
  Array<std::int32_t> p2{std::size(v)};
  std::ifstream in{"ints"};
}

int main() {
  std::int32_t arr[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  Exercise(std::begin(arr), std::end(arr));
}
