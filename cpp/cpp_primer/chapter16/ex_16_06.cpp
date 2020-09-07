//
// Created by kaiser on 18-12-27.
//

#include <algorithm>
#include <iostream>
#include <iterator>

template<typename T, auto size>
constexpr T* Begin(T (&arr)[size])
{
    return arr;
}

template<typename T, auto size>
constexpr T* End(T (&arr)[size])
{
    return arr + size;
}

int main()
{
    std::string s[]{"a", "b", "c"};
    std::copy(Begin(s), End(s),
              std::ostream_iterator<std::string>{std::cout, " "});
}
