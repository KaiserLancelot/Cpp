//
// Created by kaiser on 18-11-27.
//

#include <cstdint>
#include <iostream>
#include <stdexcept>

int main() {
  std::int32_t v1, v2;

  while (std::cin >> v1 >> v2) {
    try {
      if (v2 == 0)
        throw std::runtime_error("divisor is 0");
      std::cout << v1 / v2 << '\n';
    } catch (const std::runtime_error &error) {
      std::cout << error.what() << "\nTry again? Enter y or n\n";
      char choice;
      std::cin >> choice;
      if (!std::cin || choice == 'n')
        break;
    }
  }

}