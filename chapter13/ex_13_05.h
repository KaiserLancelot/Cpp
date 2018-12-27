//
// Created by kaiser on 18-12-20.
//

#ifndef CPP_PRIMER_EX_13_05_H
#define CPP_PRIMER_EX_13_05_H

#include <cstdint>
#include <string>

class HasPtr {
 public:
  HasPtr(const HasPtr &item) : ps_{new std::string(*item.ps_)}, i_{item.i_} {}
  explicit HasPtr(const std::string &s = std::string())
      : ps_{new std::string(s)} {}

 private:
  std::string *ps_;
  std::int32_t i_{};
};

#endif  // CPP_PRIMER_EX_13_05_H
