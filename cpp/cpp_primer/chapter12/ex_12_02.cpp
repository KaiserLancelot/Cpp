//
// Created by kaiser on 18-12-19.
//

#include "ex_12_02.h"

#include <stdexcept>

StrBlob::StrBlob() : data_{std::make_shared<std::vector<std::string>>()} {}

StrBlob::StrBlob(std::initializer_list<std::string> il)
    : data_{std::make_shared<std::vector<std::string>>(il)} {}

StrBlob::SizeType StrBlob::size() const { return std::size(*data_); }

bool StrBlob::empty() const { return std::empty(*data_); }

void StrBlob::push_back(const std::string& t) { data_->push_back(t); }

void StrBlob::pop_back()
{
    check(0, "PopBack on empty StrBlob");
    data_->pop_back();
}

std::string& StrBlob::front()
{
    check(0, "Front on empty StrBlob");
    return data_->front();
}

std::string& StrBlob::front() const
{
    check(0, "Front on empty StrBlob");
    return data_->front();
}

std::string& StrBlob::back()
{
    check(0, "Back on empty StrBlob");
    return data_->back();
}

std::string& StrBlob::back() const
{
    check(0, "Back on empty StrBlob");
    return data_->back();
}

void StrBlob::check(StrBlob::SizeType i, const std::string& msg) const
{
    if (i >= size()) {
        throw std::out_of_range{msg};
    }
}
