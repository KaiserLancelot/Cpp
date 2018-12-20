//
// Created by kaiser on 18-12-20.
//

#ifndef CPP_PRIMER_EX_13_19_H
#define CPP_PRIMER_EX_13_19_H

#include <iostream>
#include <cstdint>

class Employee {
 public:
  Employee()
      : id_{num++} {}
  Employee(const Employee &) = delete;
  Employee &operator=(const Employee &) = delete;
  explicit Employee(const std::string &name)
      : name_{name}, id_{num++} {}
 private:
  inline static std::int32_t num{};
  std::string name_;
  std::int32_t id_;
};

#endif //CPP_PRIMER_EX_13_19_H
