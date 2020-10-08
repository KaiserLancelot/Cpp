#pragma once

#include <gtest/internal/gtest-internal.h>

template <typename T>
bool float_point_equal(T lhs, T rhs) {
  testing::internal::FloatingPoint<T> lhs_value{lhs};
  testing::internal::FloatingPoint<T> rhs_value{rhs};

  return lhs_value.AlmostEquals(rhs_value);
}
