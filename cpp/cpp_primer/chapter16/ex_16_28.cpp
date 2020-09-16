//
// Created by kaiser on 19-3-4.
//

#include "ex_16_28.h"
#include <cstdint>
#include <iostream>
#include <string>

int main() {
  SharedPtr<std::int32_t> foo{new std::int32_t{42}};
  auto bar{foo};
  std::cout << *foo << '\n';
  std::cout << foo.use_count() << '\n';

  SharedPtr<std::string> string_ptr{new std::string{"Yue"}};
  std::cout << *string_ptr << '\n';
  std::cout << string_ptr->size() << '\n';

  UniquePtr<std::int32_t> foo2{new std::int32_t{42}};
  std::cout << *foo2 << '\n';

  UniquePtr<std::string> string_ptr2{new std::string{"Yue"}};
  std::cout << *string_ptr2 << '\n';
  std::cout << string_ptr2->size() << '\n';
}
