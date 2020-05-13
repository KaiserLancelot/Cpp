//
// Created by kaiser on 18-11-29.
//

#pragma once

#include <string>

class Account {
 public:
  void Calculate() { amount_ += amount_ * Account::InterestRate; }
  static double Rate() { return Account::InterestRate; }
  static void Rate(double new_rate) { Account::InterestRate = new_rate; }

 private:
  std::string owner_;
  double amount_{};
  inline static double InterestRate{42.42};
};
