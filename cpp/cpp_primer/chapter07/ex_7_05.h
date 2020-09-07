//
// Created by kaiser on 18-11-29.
//

#pragma once

#include <string>

struct Person {
    const std::string& get_name() const { return name; }

    const std::string& get_address() const { return address; }

    std::string name;
    std::string address;
};
