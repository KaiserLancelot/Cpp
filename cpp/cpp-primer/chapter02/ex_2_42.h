//
// Created by kaiser on 18-11-21.
//

#pragma once

#include <cstdint>
#include <string>

struct SalesData {
  std::string book_no;
  std::int32_t units_sold{};
  double revenue{};
};
