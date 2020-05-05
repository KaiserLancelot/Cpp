//
// Created by kaiser on 20-5-5.
//

#include <string>

using ArrType = std::string[10];

ArrType &Fun1();

auto Fun2() -> std::string (&)[10];

std::string Arr[10];

decltype(Arr) *Fun3();

int main() {}
