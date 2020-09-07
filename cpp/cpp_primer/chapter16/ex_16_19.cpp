//
// Created by kaiser on 19-3-4.
//

#include <cstdint>
#include <iostream>
#include <vector>

template<typename T>
void Print(const T& t)
{
    for (typename T::size_type index{}; index < std::size(t); ++index) {
        std::cout << t[index] << '\n';
    }
}

int main()
{
    std::vector<std::int32_t> v{1, 2, 3, 4};
    Print(v);
}
