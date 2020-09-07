//
// Created by kaiser on 18-12-5.
//

#pragma once

#include <cstdint>
#include <iostream>
#include <string>

class Date {
    friend std::ostream& print(std::ostream& os, const Date& item);

public:
    Date() = default;
    explicit Date(const std::string& s)
    {
        if (s.find("Jan") != std::string::npos) {
            month_ = 1;
        }
        else if (s.find("Feb") != std::string::npos) {
            month_ = 2;
        }
        else if (s.find("Mar") != std::string::npos) {
            month_ = 3;
        }
        else if (s.find("Apr") != std::string::npos) {
            month_ = 4;
        }
        else if (s.find("May") != std::string::npos) {
            month_ = 5;
        }
        else if (s.find("Jun") != std::string::npos) {
            month_ = 6;
        }
        else if (s.find("Jul") != std::string::npos) {
            month_ = 7;
        }
        else if (s.find("Aug") != std::string::npos) {
            month_ = 8;
        }
        else if (s.find("Sep") != std::string::npos) {
            month_ = 9;
        }
        else if (s.find("Oct") != std::string::npos) {
            month_ = 10;
        }
        else if (s.find("Nov") != std::string::npos) {
            month_ = 11;
        }
        else if (s.find("Dec") != std::string::npos) {
            month_ = 12;
        }
        else {
            month_ = std::stoi(s);
            year_ = std::stoi(s.substr(s.find_last_of('/') + 1));
            day_ = std::stoi(s.substr(s.find_first_of('/') + 1));
        }

        if (year_ == 0 && day_ == 0) {
            year_ = std::stoi(s.substr(std::size(s) - 4));
            day_ = std::stoi(s.substr(s.find_first_of("0123456789")));
        }
    }

private:
    std::int32_t year_{};
    std::int32_t month_{};
    std::int32_t day_{};
};

inline std::ostream& print(std::ostream& os, const Date& item)
{
    os << item.year_ << ' ' << item.month_ << ' ' << item.day_;
    return os;
}
