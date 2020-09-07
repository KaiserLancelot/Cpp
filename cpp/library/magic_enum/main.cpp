//
// Created by kaiser on 2020/4/27.
//

#include <iostream>
#include <string>

#include <magic_enum.hpp>

enum class Color { Red = 2,
                   Blue = 4,
                   Green = 8 };

int main()
{
    {
        auto color{Color::Red};
        std::cout << magic_enum::enum_name(color) << '\n';
    }

    {
        std::string color_name{"Green"};
        auto color{magic_enum::enum_cast<Color>(color_name)};
        if (color) {
            std::cout << "Ok\n";
        }
    }
}
