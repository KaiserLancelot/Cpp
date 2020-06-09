//
// Created by kaiser on 20-5-5.
//

#include <string>

using ArrType = std::string[10];

ArrType &fun1();

auto fun2() -> std::string (&)[10];

std::string arr[10];

decltype(arr) *fun3();

int main() {}
