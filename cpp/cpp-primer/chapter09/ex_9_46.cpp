//
// Created by kaiser on 18-12-5.
//

#include <iostream>
#include <string>

std::string &fun(std::string &name, const std::string &prefix,
                 const std::string &suffix) {
  name.insert(0, prefix);
  name.insert(std::size(name), suffix);
  return name;
}

int main() {
  std::string name("kaiser");
  std::cout << fun(name, "Mr.", " Jr.") << '\n';
}
