#include "sales_item.h"

#include <gtest/internal/gtest-internal.h>

bool compare_isbn(const SalesItem& lhs, const SalesItem& rhs) {
  return lhs.isbn() == rhs.isbn();
}

bool operator==(const SalesItem& lhs, const SalesItem& rhs) {
  testing::internal::FloatingPoint<double> lhs_revenue{lhs.revenue_};
  testing::internal::FloatingPoint<double> rhs_revenue{rhs.revenue_};

  return lhs.units_sold_ == rhs.units_sold_ &&
         lhs_revenue.AlmostEquals(rhs_revenue) && lhs.isbn() == rhs.isbn();
}

bool operator!=(const SalesItem& lhs, const SalesItem& rhs) {
  return !(lhs == rhs);
}

SalesItem& SalesItem::operator+=(const SalesItem& rhs) {
  units_sold_ += rhs.units_sold_;
  revenue_ += rhs.revenue_;
  return *this;
}

SalesItem operator+(const SalesItem& lhs, const SalesItem& rhs) {
  SalesItem ret(lhs);
  ret += rhs;
  return ret;
}

std::istream& operator>>(std::istream& in, SalesItem& s) {
  double price;
  in >> s.book_no_ >> s.units_sold_ >> price;

  if (in) {
    s.revenue_ = s.units_sold_ * price;
  } else {
    s = SalesItem();
  }

  return in;
}

std::ostream& operator<<(std::ostream& out, const SalesItem& s) {
  out << s.isbn() << " " << s.units_sold_ << " " << s.revenue_ << " "
      << s.avg_price();
  return out;
}

double SalesItem::avg_price() const {
  return units_sold_ == 0 ? 0 : revenue_ / units_sold_;
}
