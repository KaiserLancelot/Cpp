//
// Created by kaiser on 18-12-22.
//

#ifndef CPP_PRIMER_EX_13_53_H
#define CPP_PRIMER_EX_13_53_H

#include <algorithm>
#include <cstdint>
#include <string>

class HasPtr {
  friend void swap(HasPtr &lhs, HasPtr &rhs);

 public:
  explicit HasPtr(const std::string &s = std::string())
      : ps_{new std::string(s)} {}
  HasPtr(const HasPtr &item) : ps_{new std::string(*item.ps_)}, i_{item.i_} {}
  HasPtr(HasPtr &&item) noexcept : ps_{item.ps_}, i_{item.i_} {
    item.ps_ = nullptr;
  }
  HasPtr &operator=(const HasPtr &item) {
    auto temp{new std::string(*item.ps_)};
    delete ps_;
    ps_ = temp;
    i_ = item.i_;
    return *this;
  }
  HasPtr &operator=(HasPtr &&item) noexcept {
    if (this != &item) {
      delete ps_;
      ps_ = item.ps_;
      i_ = item.i_;
      item.ps_ = nullptr;
    }
    return *this;
  }
  ~HasPtr() { delete ps_; }

 private:
  std::string *ps_;
  std::int32_t i_{};
};

inline void swap(HasPtr &lhs, HasPtr &rhs) {
  using std::swap;
  swap(lhs.ps_, rhs.ps_);
  swap(lhs.i_, rhs.i_);
}

#endif  // CPP_PRIMER_EX_13_53_H
