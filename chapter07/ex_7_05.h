//
// Created by kaiser on 18-11-29.
//

#ifndef CPP_PRIMER_EX_7_5_H
#define CPP_PRIMER_EX_7_5_H

#include <string>

struct Person {
    const std::string &GetName() const {
        return name_;
    }

    const std::string &GetAddress() const {
        return address_;
    }

    std::string name_;
    std::string address_;
};

#endif //CPP_PRIMER_EX_7_5_H
