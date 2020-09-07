//
// Created by kaiser on 18-12-27.
//

#include <iostream>
#include <string>

template<typename T>
void Print(const T& arr)
{
    for (const auto& ele : arr) {
        std::cout << ele << '\n';
    }
}

int main()
{
    std::string s[]{"a", "b", "c"};
    Print(s);
}
