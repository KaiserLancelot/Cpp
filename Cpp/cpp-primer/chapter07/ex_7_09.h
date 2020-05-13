//
// Created by kaiser on 18-11-29.
//

#pragma once

#include <iostream>
#include <string>

struct Person {
  const std::string &GetName() const { return name; }

  const std::string &GetAddress() const { return address; }

  std::string name;
  std::string address;
};

inline std::istream &Read(std::istream &is, Person &item) {
  is >> item.name >> item.address;
  return is;
}

inline std::ostream &Print(std::ostream &os, const Person &item) {
  os << item.name << ' ' << item.address;
  return os;
}
