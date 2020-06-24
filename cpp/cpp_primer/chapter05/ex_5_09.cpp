//
// Created by kaiser on 18-11-27.
//

#include <cstdint>
#include <iostream>

int main() {
  std::int32_t a_count{}, e_count{}, i_count{}, o_count{}, u_count{};
  char ch;

  while (std::cin >> ch) {
    if (ch == 'a') {
      ++a_count;
    } else if (ch == 'e') {
      ++e_count;
    } else if (ch == 'i') {
      ++i_count;
    } else if (ch == 'o') {
      ++o_count;
    } else if (ch == 'u') {
      ++u_count;
    }
  }
  std::cout << a_count << ' ' << e_count << ' ' << i_count << ' ' << o_count
            << ' ' << u_count << '\n';
}
