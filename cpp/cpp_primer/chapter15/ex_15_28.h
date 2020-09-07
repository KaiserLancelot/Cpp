//
// Created by kaiser on 18-12-25.
//

#ifndef CPP_PRIMER_EX_15_28_H
#define CPP_PRIMER_EX_15_28_H

#include <cstdint>
#include <iostream>
#include <string>

#include <cstdint>
#include <iostream>
#include <string>

class Quote {
public:
    Quote() = default;
    Quote(const std::string& book_no, double price)
        : price_{price}, book_no_{book_no} {}
    virtual ~Quote() = default;
    std::string Isbn() const { return book_no_; }
    virtual double NetPrice(std::int32_t n) const { return n * price_; }
    virtual void Debug() const { std::cout << book_no_ << ' ' << price_ << '\n'; }

protected:
    double price_{};

private:
    std::string book_no_;
};

class DiscQuote : public Quote {
public:
    DiscQuote() = default;
    DiscQuote(const std::string& book_no, double price, int32_t quantity,
              double discount)
        : Quote(book_no, price), quantity_(quantity), discount_(discount) {}
    double NetPrice(std::int32_t n) const override = 0;

protected:
    std::int32_t quantity_{};
    double discount_{};
};

class BulkQuote : public DiscQuote {
public:
    BulkQuote(const std::string& book_no, double price, int32_t quantity,
              double discount)
        : DiscQuote(book_no, price, quantity, discount) {}

    double NetPrice(std::int32_t n) const override
    {
        if (n >= quantity_)
            return n * (1 - discount_) * price_;
        else
            return n * price_;
    }
    void Debug() const override
    {
        std::cout << Isbn() << ' ' << price_ << ' ' << quantity_ << ' ' << discount_
                  << '\n';
    }
};

class LimitQuote : public DiscQuote {
public:
    LimitQuote(const std::string& book_no, double price, int32_t quantity,
               double discount)
        : DiscQuote(book_no, price, quantity, discount) {}

    double NetPrice(std::int32_t n) const override
    {
        if (n < quantity_)
            return n * price_ * (1 - discount_);
        else
            return n * price_;
    }
    void Debug() const override
    {
        std::cout << Isbn() << ' ' << price_ << ' ' << quantity_ << ' ' << discount_
                  << '\n';
    }
};

#endif // CPP_PRIMER_EX_15_28_H
