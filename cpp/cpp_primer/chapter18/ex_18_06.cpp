//
// Created by kaiser on 19-3-14.
//

#include <iostream>

class ExceptionType {};

int main() {
  try {
    ExceptionType e;
    throw &e;
  } catch (ExceptionType* pet) {
    std::cout << "ExceptionType *pet\n";
  }

  try {
    throw ExceptionType{};
  } catch (...) {
    std::cout << "...\n";
  }

  using Excptype = int;
  try {
    throw 1;
  } catch (Excptype) {
    std::cout << "Excptype\n";
  }
}
