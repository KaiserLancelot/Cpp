//
// Created by kaiser on 18-12-25.
//

#ifndef CPP_PRIMER_EX_15_30_QUOTE_H
#define CPP_PRIMER_EX_15_30_QUOTE_H

#include <cstdint>
#include <string>
#include <iostream>
#include <cstddef>

class Quote {
 public:
  Quote() = default;
  Quote(const std::string &book_no, double price)
      : price_{price}, book_no_{book_no} {}
  Quote(const Quote &) = default;
  Quote(Quote &&) noexcept = default;
  Quote &operator=(const Quote &) = default;
  Quote &operator=(Quote &&) noexcept = default;
  virtual ~Quote() = default;
  std::string Isbn() const { return book_no_; }
  virtual double NetPrice(std::int32_t n) const { return n * price_; }
  virtual void Debug() const {
    std::cout << book_no_ << ' ' << price_ << '\n';
  }
  virtual Quote *clone() const &{
    return new Quote{*this};
  }
  virtual Quote *clone() &&{
    return new Quote{std::move(*this)};
  }
 protected:
  double price_{};
 private:
  std::string book_no_;
};

class DiscQuote : public Quote {
 public:
  DiscQuote() = default;
  DiscQuote(const std::string &book_no, double price,
            int32_t quantity, double discount)
      : Quote(book_no, price), quantity_(quantity), discount_(discount) {}
  double NetPrice(std::int32_t n) const override = 0;
 protected:
  std::int32_t quantity_{};
  double discount_{};
};

class BulkQuote : public DiscQuote {
 public:
  BulkQuote(const std::string &book_no, double price, int32_t quantity, double discount)
      : DiscQuote(book_no, price, quantity, discount) {}
  BulkQuote(const BulkQuote &item) = default;
  BulkQuote(BulkQuote &&item) noexcept = default;
  BulkQuote &operator=(const BulkQuote &item) = default;
  BulkQuote &operator=(BulkQuote &&item) noexcept = default;
  BulkQuote *clone() const & override {
    return new BulkQuote{*this};
  }
  BulkQuote *clone() && override {
    return new BulkQuote{std::move(*this)};
  }
  double NetPrice(std::int32_t n) const override {
    if (n >= quantity_)
      return n * (1 - discount_) * price_;
    else
      return n * price_;
  }
  void Debug() const override {
    std::cout << Isbn() << ' ' << price_ << ' ' <<
              quantity_ << ' ' << discount_ << '\n';
  }
};

class LimitQuote : public DiscQuote {
 public:
  LimitQuote(const std::string &book_no, double price, int32_t quantity, double discount)
      : DiscQuote(book_no, price, quantity, discount) {}

  double NetPrice(std::int32_t n) const override {
    if (n < quantity_)
      return n * price_ * (1 - discount_);
    else
      return n * price_;
  }
  void Debug() const override {
    std::cout << Isbn() << ' ' << price_ << ' ' <<
              quantity_ << ' ' << discount_ << '\n';
  }
};

double PrintTotal(std::ostream &os, const Quote &item, std::size_t n);

#endif //CPP_PRIMER_EX_15_30_QUOTE_H
