//
// Created by kaiser on 18-12-25.
//

#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdint>

class Foo {
 public:
  Foo sorted() &&{
    std::cout << "&&\n";
    std::sort(std::begin(data_), std::end(data_));
    return *this;
  }
  Foo sorted() const &{
    std::cout << "&\n";
    return Foo{*this}.sorted();
  }
 private:
  std::vector<std::int32_t> data_;
};

int main() {
  Foo{}.sorted();
  Foo f;
  f.sorted();
}