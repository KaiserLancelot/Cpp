//
// Created by kaiser on 2020/4/27.
//

#include <iostream>
#include <string>

#include <magic_enum.hpp>

enum class Color { kRed = 2, kBlue = 4, kGreen = 8 };

int main() {
  {
    auto color{Color::kRed};
    std::cout << magic_enum::enum_name(color) << '\n';
  }

  {
    std::string color_name{"kGreen"};
    auto color{magic_enum::enum_cast<Color>(color_name)};
    if (color) {
      std::cout << "Ok\n";
    }
  }
}
