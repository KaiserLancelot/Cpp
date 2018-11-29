//
// Created by kaiser on 18-11-29.
//

#ifndef CPP_PRIMER_EX_7_57_H
#define CPP_PRIMER_EX_7_57_H

#include <string>

class Account {
public:
    void Calculate() { amount += amount * Account::interest_rate_; }
    static double Rate() { return Account::interest_rate_; }
    static void Rate(double new_rate) {
        Account::interest_rate_ = new_rate;
    }
private:
    std::string owner_;
    double amount{};
    inline static double interest_rate_{42.42};
};

#endif //CPP_PRIMER_EX_7_57_H
