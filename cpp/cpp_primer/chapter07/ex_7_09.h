//
// Created by kaiser on 18-11-29.
//

#pragma once

#include <iostream>
#include <string>

struct Person {
    const std::string& get_name() const { return name; }

    const std::string& get_address() const { return address; }

    std::string name;
    std::string address;
};

inline std::istream& read(std::istream& is, Person& item)
{
    is >> item.name >> item.address;
    return is;
}

inline std::ostream& print(std::ostream& os, const Person& item)
{
    os << item.name << ' ' << item.address;
    return os;
}
