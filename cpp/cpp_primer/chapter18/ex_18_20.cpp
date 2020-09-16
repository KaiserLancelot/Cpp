//
// Created by kaiser on 19-3-15.
//

#include <iostream>

namespace primerLib {
void compute() { std::cout << "compute()\n"; }

void compute(const void*) { std::cout << "compute(const void*)\n"; };
}  // namespace primerLib

void compute(int) { std::cout << "compute(int)\n"; };

void compute(double, double = 3.4) {
  std::cout << "compute(double, double = 3.4)\n";
}
void compute(char*, char* = nullptr) {
  std::cout << "compute(char*, char* = nullptr)\n";
}

void f() {
  // using primerLib::compute;
  compute(0);
}

int main() { f(); }
