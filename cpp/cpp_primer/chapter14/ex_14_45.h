//
// Created by kaiser on 18-12-24.
//

#ifndef CPP_PRIMER_EX_14_45_H
#define CPP_PRIMER_EX_14_45_H

#include <cstdint>
#include <iostream>
#include <string>

class SalesData {
    friend std::ostream& operator<<(std::ostream& os, const SalesData& item);
    friend std::istream& operator>>(std::istream& is, SalesData& item);

public:
    SalesData() = default;
    explicit SalesData(const std::string& book_no);
    SalesData(const std::string& book_no, std::int32_t units_sold,
              double revenue);
    explicit SalesData(std::istream& is);
    SalesData& operator+=(const SalesData& rhs);
    const std::string& Isbn() const;
    explicit operator std::string() const;
    explicit operator double() const;

private:
    double AvgPrice() const;

    std::string book_no_;
    std::int32_t units_sold_{};
    double revenue_{};
};

std::ostream& operator<<(std::ostream& os, const SalesData& item);
std::istream& operator>>(std::istream& is, SalesData& item);
SalesData operator+(const SalesData& lhs, const SalesData& rhs);

#endif // CPP_PRIMER_EX_14_45_H
