#pragma once

#include <cstdint>
#include <string>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpadded"
struct SalesData {
  std::string book_no_;
  double revenue_{};
  std::int32_t units_sold_{};
};
#pragma GCC diagnostic pop
