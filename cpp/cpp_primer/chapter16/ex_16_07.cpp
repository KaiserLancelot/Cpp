//
// Created by kaiser on 18-12-27.
//

#include <iostream>
#include <string>

template<typename T, auto Size>
auto GetSize(const T (&arr)[Size])
{
    return Size;
}

int main()
{
    std::string s[]{"a", "b", "c"};
    std::cout << GetSize(s) << '\n';
}
