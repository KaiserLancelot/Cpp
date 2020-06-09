//
// Created by kaiser on 18-11-28.
//

#include <cstdlib>
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    std::cerr << "error" << std::endl;
    return EXIT_FAILURE;
  }

  std::cout << std::string{argv[1]} + argv[2] << '\n';
}
