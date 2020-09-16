//
// Created by kaiser on 18-12-20.
//

#ifndef CPP_PRIMER_EX_13_18_H
#define CPP_PRIMER_EX_13_18_H

#include <cstdint>
#include <iostream>

class Employee {
 public:
  Employee() : id_{num++} {}
  explicit Employee(const std::string& name) : name_{name}, id_{num++} {}

 private:
  inline static std::int32_t num{};
  std::string name_;
  std::int32_t id_;
};

#endif  // CPP_PRIMER_EX_13_18_H
