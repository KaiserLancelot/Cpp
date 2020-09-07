//
// Created by kaiser on 18-12-20.
//

#ifndef CPP_PRIMER_EX_13_22_H
#define CPP_PRIMER_EX_13_22_H

#include <cstdint>
#include <string>

class HasPtr {
public:
    explicit HasPtr(const std::string& s = std::string())
        : ps_{new std::string(s)} {}
    HasPtr(const HasPtr& item) : ps_{new std::string(*item.ps_)}, i_{item.i_} {}
    HasPtr& operator=(const HasPtr& item)
    {
        auto temp{new std::string(*item.ps_)};
        delete ps_;
        ps_ = temp;
        i_ = item.i_;
        return *this;
    }
    ~HasPtr() { delete ps_; }

private:
    std::string* ps_;
    std::int32_t i_{};
};

#endif // CPP_PRIMER_EX_13_22_H
