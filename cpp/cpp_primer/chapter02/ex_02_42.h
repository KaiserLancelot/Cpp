#pragma once

#include <cstdint>
#include <string>

struct SalesData {
  std::string book_no_;
  double revenue_{};
  std::int32_t units_sold_{};
};
