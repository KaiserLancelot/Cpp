//
// Created by kaiser on 19-3-6.
//

#include "sales_data.h"

#include <cstring>
#include <functional>

template <typename T>
int compare(const T &t1, const T &t2) {
  if (std::less<>{}(t1, t2)) {
    return -1;
  } else if (std::less<>{}(t2, t1)) {
    return 1;
  } else {
    return 0;
  }
}

template <>
int compare(const char *const &t1, const char *const &t2) {
  return strcmp(t1, t2);
}

int main() {}