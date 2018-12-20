//
// Created by kaiser on 18-11-28.
//

#include <iostream>
#include <string>
#include <cstdint>

std::string MakePlural(std::size_t ctr, const std::string &word,
                       const std::string &ending = "s") {
  return (ctr > 1) ? word + ending : word;
}

int main() {
  std::cout << MakePlural(10, "success") << '\n';
  std::cout << MakePlural(10, "failure") << '\n';
}