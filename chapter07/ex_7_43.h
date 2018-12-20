//
// Created by kaiser on 18-11-29.
//

#ifndef CPP_PRIMER_EX_7_43_H
#define CPP_PRIMER_EX_7_43_H

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

#endif //CPP_PRIMER_EX_7_43_H
