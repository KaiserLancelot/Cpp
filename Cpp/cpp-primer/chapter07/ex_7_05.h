//
// Created by kaiser on 18-11-29.
//

#pragma once

#include <string>

struct Person {
  const std::string &GetName() const { return name; }

  const std::string &GetAddress() const { return address; }

  std::string name;
  std::string address;
};
