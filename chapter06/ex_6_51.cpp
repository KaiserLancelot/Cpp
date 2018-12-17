//
// Created by kaiser on 18-11-28.
//

#include <iostream>

void f() {
    std::cout << "f()\n";
}

void f(int) {
    std::cout << "f(int)\n";
}

void f(int, int) {
    std::cout << "f(int, int)\n";
}

void f(double, double) {
    std::cout << "f(double, double)\n";
}

int main() {
    //f(2.56, 42); // error
    f(42);
    f(42, 0);
    f(2.56, 3.14);
}