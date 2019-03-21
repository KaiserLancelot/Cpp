//
// Created by kaiser on 18-11-29.
//

#ifndef CPP_PRIMER_EX_7_9_H
#define CPP_PRIMER_EX_7_9_H

#include <iostream>
#include <string>

struct Person {
  const std::string &GetName() const { return name_; }

  const std::string &GetAddress() const { return address_; }

  std::string name_;
  std::string address_;
};

inline std::istream &Read(std::istream &is, Person &item) {
  is >> item.name_ >> item.address_;
  return is;
}

inline std::ostream &Print(std::ostream &os, const Person &item) {
  os << item.name_ << ' ' << item.address_;
  return os;
}

#endif  // CPP_PRIMER_EX_7_9_H
