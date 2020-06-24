//
// Created by kaiser on 18-11-29.
//

#pragma once

#include <iostream>
#include <string>

class Person;
std::istream &read(std::istream &is, Person &item);

class Person {
  friend std::istream &read(std::istream &is, Person &item);
  friend std::ostream &print(std::ostream &os, const Person &item);

public:
  Person() = default;
  Person(const std::string &name, const std::string &address)
      : name_(name), address_(address) {}
  explicit Person(std::istream &is) { read(is, *this); }

  const std::string &get_name() const { return name_; }

  const std::string &get_address() const { return address_; }

private:
  std::string name_;
  std::string address_;
};

inline std::istream &read(std::istream &is, Person &item) {
  is >> item.name_ >> item.address_;
  return is;
}

inline std::ostream &print(std::ostream &os, const Person &item) {
  os << item.name_ << ' ' << item.address_;
  return os;
}
