//
// Created by kaiser on 18-12-5.
//

#include <iostream>
#include <string>

std::string &fun(std::string &name, const std::string &prefix,
                 const std::string &suffix) {
  name.insert(std::begin(name), std::begin(prefix), std::end(prefix));
  name.append(suffix);
  return name;
}

int main() {
  std::string name("kaiser");
  std::cout << fun(name, "Mr.", " Jr.") << '\n';
}
