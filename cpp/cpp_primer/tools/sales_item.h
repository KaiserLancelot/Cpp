#pragma once

#include <cstdint>
#include <iostream>
#include <string>

#include "float_point.h"

class SalesItem;

std::istream& operator>>(std::istream& in, SalesItem& s);
std::ostream& operator<<(std::ostream& out, const SalesItem& s);
bool operator==(const SalesItem& lhs, const SalesItem& rhs);

class SalesItem {
  friend std::istream& operator>>(std::istream& in, SalesItem& s);
  friend std::ostream& operator<<(std::ostream& out, const SalesItem& s);
  friend bool operator==(const SalesItem& lhs, const SalesItem& rhs);

 public:
  SalesItem() = default;
  explicit SalesItem(const std::string& book) : book_no_{book} {}
  explicit SalesItem(std::istream& is) { is >> *this; }

  SalesItem& operator+=(const SalesItem& rhs);

  [[nodiscard]] std::string isbn() const { return book_no_; }
  [[nodiscard]] double avg_price() const;

 private:
  std::string book_no_;
  double revenue_{};
  std::int32_t units_sold_{};
};

inline bool compare_isbn(const SalesItem& lhs, const SalesItem& rhs) {
  return lhs.isbn() == rhs.isbn();
}

inline bool operator==(const SalesItem& lhs, const SalesItem& rhs) {
  return lhs.units_sold_ == rhs.units_sold_ &&
         float_point_equal(lhs.revenue_, rhs.revenue_) &&
         lhs.isbn() == rhs.isbn();
}

inline bool operator!=(const SalesItem& lhs, const SalesItem& rhs) {
  return !(lhs == rhs);
}

inline SalesItem& SalesItem::operator+=(const SalesItem& rhs) {
  units_sold_ += rhs.units_sold_;
  revenue_ += rhs.revenue_;
  return *this;
}

inline SalesItem operator+(const SalesItem& lhs, const SalesItem& rhs) {
  SalesItem ret(lhs);
  ret += rhs;
  return ret;
}

inline std::istream& operator>>(std::istream& in, SalesItem& s) {
  double price;
  in >> s.book_no_ >> s.units_sold_ >> price;

  if (in) {
    s.revenue_ = s.units_sold_ * price;
  } else {
    s = SalesItem();
  }

  return in;
}

inline std::ostream& operator<<(std::ostream& out, const SalesItem& s) {
  out << s.isbn() << " " << s.units_sold_ << " " << s.revenue_ << " "
      << s.avg_price();
  return out;
}

inline double SalesItem::avg_price() const {
  return units_sold_ == 0 ? 0 : revenue_ / units_sold_;
}
