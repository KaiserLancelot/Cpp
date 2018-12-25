//
// Created by kaiser on 18-12-25.
//

#ifndef CPP_PRIMER_EX_15_27_H
#define CPP_PRIMER_EX_15_27_H

#include <cstdint>
#include <string>
#include <iostream>

class Quote {
 public:
  Quote() {
    std::cout << "Quote()\n";
  }
  Quote(const std::string &book_no, double price)
      : price_{price}, book_no_{book_no} {
    std::cout << "Quote(const std::string &book_no, double price)\n";
  }
  Quote(const Quote &) {
    std::cout << "Quote(const Quote &item)\n";
  }
  Quote(Quote &&) noexcept {
    std::cout << "Quote(Quote &&)\n";
  }
  Quote &operator=(const Quote &) {
    std::cout << "operator=(const Quote &)\n";
    return *this;
  }
  Quote &operator=(Quote &&) noexcept {
    std::cout << "operator=(Quote&&)\n";
    return *this;
  }
  virtual ~Quote() {
    std::cout << "~Quote()\n";
  }
  std::string Isbn() const { return book_no_; }
  virtual double NetPrice(std::int32_t n) const { return n * price_; }
  virtual void Debug() const {
    std::cout << book_no_ << ' ' << price_ << '\n';
  }
 protected:
  double price_{};
 private:
  std::string book_no_;
};

class BulkQuote : public Quote {
 public:
  using Quote::Quote;
  BulkQuote() {
    std::cout << "BulkQuote()\n";
  }
  BulkQuote(const std::string &book_no, double price,
            int32_t quantity, double discount)
      : Quote(book_no, price), quantity_{quantity}, discount_{discount} {
    std::cout << "BulkQuote(const std::string &book_no, "
                 "double price, int32_t quantity, double discount)\n";
  }
  BulkQuote(const BulkQuote &item) : Quote{item} {
    std::cout << "BulkQuote(const BulkQuote &item)\n";
  }
  BulkQuote(BulkQuote &&item) noexcept: Quote{std::move(item)} {
    std::cout << "BulkQuote(BulkQuote &&)\n";
  }
  BulkQuote &operator=(const BulkQuote &item) {
    Quote::operator=(item);
    std::cout << "operator=(const BulkQuote &)\n";
    return *this;
  }
  BulkQuote &operator=(BulkQuote &&item) noexcept {
    Quote::operator=(item);
    std::cout << "operator=(BulkQuote&&)\n";
    return *this;
  }
  ~BulkQuote() override {
    std::cout << "~BulkQuote()\n";
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
 private:
  std::int32_t quantity_{};
  double discount_{};
};

#endif //CPP_PRIMER_EX_15_27_H
