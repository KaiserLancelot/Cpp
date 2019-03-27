//
// Created by kaiser on 19-3-27.
//

#include <fmt/color.h>
#include <fmt/core.h>

int main() {
  fmt::print("Hello World\n");
  // fg 指 foreground
  fmt::print(fg(fmt::terminal_color::red), "Hello World\n");
  fmt::print(fg(fmt::terminal_color::yellow), "Hello World\n");
}