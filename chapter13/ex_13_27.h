//
// Created by kaiser on 18-12-20.
//

#ifndef CPP_PRIMER_EX_13_27_H
#define CPP_PRIMER_EX_13_27_H

#include <string>
#include <cstdint>
#include <cstddef>

class HasPtr {
 public:
  explicit HasPtr(const std::string &s = std::string())
      : ps_{new std::string(s)}, use_{new std::size_t{1}} {}
  HasPtr(const HasPtr &item)
      : ps_{item.ps_}, i_{item.i_}, use_{item.use_} {
    ++*use_;
  }
  HasPtr &operator=(const HasPtr &item) {
    ++*item.use_;
    if (--*use_ == 0) {
      delete ps_;
      delete use_;
    }

    ps_ = item.ps_;
    i_ = item.i_;
    use_ = item.use_;
    return *this;
  }
  ~HasPtr() {
    if (--*use_ == 0) {
      delete ps_;
      delete use_;
    }
  }
 private:
  std::string *ps_;
  std::int32_t i_{};
  std::size_t *use_;
};

#endif //CPP_PRIMER_EX_13_27_H
