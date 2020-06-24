//
// Created by kaiser on 18-11-29.
//

#pragma once

#include <string>

class Account {
public:
  void calculate() { amount_ += amount_ * Account::interest_rate; }
  static double rate() { return Account::interest_rate; }
  static void rate(double new_rate) { Account::interest_rate = new_rate; }

private:
  std::string owner_;
  double amount_{};
  inline static double interest_rate{42.42};
};
