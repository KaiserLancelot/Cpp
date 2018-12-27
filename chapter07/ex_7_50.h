//
// Created by kaiser on 18-11-29.
//

#ifndef CPP_PRIMER_EX_7_50_H
#define CPP_PRIMER_EX_7_50_H

#include <iostream>
#include <string>

class Person;
std::istream &Read(std::istream &is, Person &item);

class Person {
  friend std::istream &Read(std::istream &is, Person &item);
  friend std::ostream &Print(std::ostream &os, const Person &item);

 public:
  Person() = default;
  Person(const std::string &name, const std::string &address)
      : name_(name), address_(address) {}
  explicit Person(std::istream &is) { Read(is, *this); }

  const std::string &GetName() const { return name_; }

  const std::string &GetAddress() const { return address_; }

 private:
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

#endif  // CPP_PRIMER_EX_7_50_H
