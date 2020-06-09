//
// Created by kaiser on 18-12-17.
//

#include <iostream>

int main() {
  std::cout << [](auto a, auto b) { return a + b; }(1, 2) << '\n';
}
