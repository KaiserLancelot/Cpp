//
// Created by kaiser on 18-11-27.
//

#include <cstdint>
#include <iostream>

int main() {
  std::int32_t a_count{}, e_count{}, i_count{}, o_count{}, u_count{};
  char ch;

  while (std::cin >> ch) {
    switch (ch) {
      case 'A':
      case 'a':
        ++a_count;
        break;
      case 'E':
      case 'e':
        ++e_count;
        break;
      case 'I':
      case 'i':
        ++i_count;
        break;
      case 'O':
      case 'o':
        ++o_count;
        break;
      case 'U':
      case 'u':
        ++u_count;
        break;
      default: {}
    }
  }
  std::cout << a_count << ' ' << e_count << ' ' << i_count << ' ' << o_count
            << ' ' << u_count << '\n';
}