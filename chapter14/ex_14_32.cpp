//
// Created by kaiser on 18-12-23.
//

#include "ex_14_32.h"

StrBlobPtr &HasStrBlobPtr::operator*() const { return *p_; }

StrBlobPtr *HasStrBlobPtr::operator->() const { return &operator*(); }
