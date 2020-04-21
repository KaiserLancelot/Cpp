//
// Created by kaiser on 20-4-22.
//

#include <cstddef>
#include <cstring>
#include <iostream>
#include <iterator>

int main() {
  const char kS1[] = "aaa";
  const char kS2[] = "bbb";

  constexpr std::size_t kSize{std::size(kS1) + std::size(kS2) - 1};
  char s[kSize];

  std::strcpy(s, kS1);
  std::strcat(s, kS2);

  std::cout << s << '\n';
}
