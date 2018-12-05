//
// Created by kaiser on 18-12-5.
//

#include <string>
#include <iostream>

std::string &Fun(std::string &name, const std::string &prefix, const std::string &suffix) {
    name.insert(std::begin(name), std::begin(prefix), std::end(prefix));
    name.append(suffix);
    return name;
}

int main() {
    std::string name("kaiser");
    std::cout << Fun(name, "Mr.", " Jr.") << '\n';
}