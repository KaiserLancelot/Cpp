//
// Created by kaiser on 18-11-26.
//

#include <iostream>
#include <cstdint>

int main()
{
    std::cout << "nullptr_t\t" << sizeof(std::nullptr_t) << " bytes" << "\n\n";

    std::cout << "bool:\t\t" << sizeof(bool) << " bytes" << "\n\n";

    std::cout << "char:\t\t" << sizeof(char) << " bytes" << '\n';
    std::cout << "wchar_t:\t" << sizeof(wchar_t) << " bytes" << '\n';
    std::cout << "char16_t:\t" << sizeof(char16_t) << " bytes" << '\n';
    std::cout << "char32_t:\t" << sizeof(char32_t) << " bytes" << "\n\n";

    std::cout << "short:\t\t" << sizeof(short) << " bytes" << '\n';
    std::cout << "int:\t\t" << sizeof(int) << " bytes" << '\n';
    std::cout << "long:\t\t" << sizeof(long) << " bytes" << '\n';
    std::cout << "long long:\t" << sizeof(long long) << " bytes" << "\n\n";

    std::cout << "float:\t\t" << sizeof(float) << " bytes" << '\n';
    std::cout << "double:\t\t" << sizeof(double) << " bytes" << '\n';
    std::cout << "long double:\t" << sizeof(long double) << " bytes" << "\n\n";

    std::cout << "int8_t:\t\t" << sizeof(std::int8_t) << " bytes" << '\n';
    std::cout << "uint8_t:\t" << sizeof(std::uint8_t) << " bytes" << '\n';
    std::cout << "int16_t:\t" << sizeof(std::int16_t) << " bytes" << '\n';
    std::cout << "uint16_t:\t" << sizeof(std::uint16_t) << " bytes" << '\n';
    std::cout << "int32_t:\t" << sizeof(std::int32_t) << " bytes" << '\n';
    std::cout << "uint32_t:\t" << sizeof(std::uint32_t) << " bytes" << '\n';
    std::cout << "int64_t:\t" << sizeof(std::int64_t) << " bytes" << '\n';
    std::cout << "uint64_t:\t" << sizeof(std::uint64_t) << " bytes" << '\n';
}