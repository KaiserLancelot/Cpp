//
// Created by kaiser on 18-12-27.
//

#include <cstdint>
#include <iostream>
#include <list>
#include <string>
#include <vector>

template <typename Iterator, typename T>
Iterator Find(Iterator begin, Iterator end, T value) {
  for (; begin != end; ++begin) {
    if (*begin == value) return begin;
  }
  return end;
}

int main() {
  std::vector<std::int32_t> v{1, 2, 3};
  if (auto iter{Find(std::cbegin(v), std::cend(v), 2)}; iter != std::cend(v))
    std::cout << *iter << '\n';
  else
    std::cout << "not found.\n";

  std::list<std::string> l{"a", "b", "c"};
  if (auto iter{Find(std::cbegin(l), std::cend(l), "d")}; iter != std::cend(l))
    std::cout << *iter << '\n';
  else
    std::cout << "not found.\n";
}