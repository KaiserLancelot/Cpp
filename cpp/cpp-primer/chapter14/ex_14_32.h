//
// Created by kaiser on 18-12-23.
//

#ifndef CPP_PRIMER_EX_14_32_H
#define CPP_PRIMER_EX_14_32_H

#include "ex_14_30.h"

#include <memory>

class HasStrBlobPtr {
public:
  StrBlobPtr &operator*() const;
  StrBlobPtr *operator->() const;

private:
  std::shared_ptr<StrBlobPtr> p_;
};

#endif // CPP_PRIMER_EX_14_32_H
