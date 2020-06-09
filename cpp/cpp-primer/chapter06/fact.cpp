//
// Created by kaiser on 18-11-28.
//

#include "chapter6.h"

#include <cstdint>

std::int32_t fact(std::int32_t val) {
  std::int32_t ret{1};
  while (val > 1) {
    ret *= val;
    --val;
  }
  return ret;
}
