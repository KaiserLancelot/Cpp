#pragma once

#include <cstdint>
#include <iostream>
#include <string>

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

SalesItem operator+(const SalesItem& lhs, const SalesItem& rhs);
bool operator!=(const SalesItem& lhs, const SalesItem& rhs);

bool compare_isbn(const SalesItem& lhs, const SalesItem& rhs);
