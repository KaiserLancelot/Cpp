//
// Created by kaiser on 18-11-29.
//

#pragma once

#include <cstdint>

class NoDefault {
public:
    NoDefault(std::int32_t i);
};

class C {
public:
    C() : no_default_{1} {}

private:
    NoDefault no_default_;
};
