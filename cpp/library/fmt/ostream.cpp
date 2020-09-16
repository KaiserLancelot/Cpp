//
// Created by kaiser on 19-3-13.
//

#include <cstdint>
#include <iostream>
#include <sstream>

#include <fmt/ostream.h>

class Date {
  friend std::ostream& operator<<(std::ostream& os, const Date& d);

 public:
  Date() = default;
  Date(std::int32_t year, std::int32_t month, std::int32_t day)
      : year_{year}, month_{month}, day_{day} {}

 private:
  std::int32_t year_{}, month_{}, day_{};
};

std::ostream& operator<<(std::ostream& os, const Date& d) {
  return os << d.year_ << '-' << d.month_ << '-' << d.day_;
}

int main() {
  Date date{2019, 3, 13};
  // 需要定义 operator<<
  fmt::print("{}\n", date);
  fmt::print(std::cerr, "{}\n", date);

  std::ostringstream ost;
  fmt::print(ost, "{}\n", date);
  fmt::print("{}\n", ost.str());
}
