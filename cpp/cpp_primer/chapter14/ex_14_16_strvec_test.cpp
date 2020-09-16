//
// Created by kaiser on 18-12-23.
//

#include "ex_14_16_strvec.h"

#include <iostream>

int main() {
  StrVec s{"a", "b", "c"};
  StrVec s2{"a", "b", "c"};
  StrVec s3{"a", "d", "c"};

  std::cout << std::boolalpha << (s == s2) << '\n';
  std::cout << (s == s3) << '\n';
}
