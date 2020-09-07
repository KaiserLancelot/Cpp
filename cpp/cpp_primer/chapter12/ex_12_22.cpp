//
// Created by kaiser on 18-12-19.
//

#include "ex_12_22.h"

#include <stdexcept>

StrBlob::StrBlob() : data_{std::make_shared<std::vector<std::string>>()} {}

StrBlob::StrBlob(std::initializer_list<std::string> il)
    : data_{std::make_shared<std::vector<std::string>>(il)} {}

StrBlobPtr StrBlob::begin() { return StrBlobPtr{*this}; }

StrBlobPtr StrBlob::end() { return StrBlobPtr{*this, std::size(*data_)}; }

ConstStrBlobPtr StrBlob::begin() const { return ConstStrBlobPtr{*this}; }

ConstStrBlobPtr StrBlob::end() const
{
    return ConstStrBlobPtr{*this, std::size(*data_)};
}

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

const std::string& StrBlob::front() const
{
    check(0, "Front on empty StrBlob");
    return data_->front();
}

std::string& StrBlob::back()
{
    check(0, "Back on empty StrBlob");
    return data_->back();
}

const std::string& StrBlob::back() const
{
    check(0, "Back on empty StrBlob");
    return data_->back();
}

std::string& StrBlob::at(SizeType index) { return data_->at(index); }

const std::string& StrBlob::at(SizeType index) const
{
    return data_->at(index);
}

void StrBlob::check(StrBlob::SizeType i, const std::string& msg) const
{
    if (i >= size()) {
        throw std::out_of_range{msg};
    }
}

StrBlobPtr::StrBlobPtr(StrBlob& a, SizeType sz) : wptr_{a.data_}, curr_{sz} {}

std::string& StrBlobPtr::deref() const
{
    auto p{check(curr_, "dereference past end")};
    return (*p)[curr_];
}

StrBlobPtr& StrBlobPtr::incr()
{
    check(curr_, "increment past end of StrBlobPtr");
    ++curr_;
    return *this;
}

bool StrBlobPtr::not_equal(const StrBlobPtr& item) const
{
    return curr_ != item.curr_;
}

std::shared_ptr<std::vector<std::string>>
StrBlobPtr::check(StrBlobPtr::SizeType i, const std::string& msg) const
{
    auto ret{wptr_.lock()};
    if (!ret) {
        throw std::runtime_error{"unbound StrBlobPtr"};
    }
    if (i >= std::size(*ret)) {
        throw std::out_of_range{msg};
    }

    return ret;
}

ConstStrBlobPtr::ConstStrBlobPtr(const StrBlob& a, ConstStrBlobPtr::SizeType sz)
    : wptr_{a.data_}, curr_{sz} {}

std::string& ConstStrBlobPtr::deref() const
{
    auto p{check(curr_, "dereference past end")};
    return (*p)[curr_];
}

ConstStrBlobPtr& ConstStrBlobPtr::incr()
{
    check(curr_, "increment past end of StrBlobPtr");
    ++curr_;
    return *this;
}

bool ConstStrBlobPtr::not_equal(const ConstStrBlobPtr& item) const
{
    return curr_ != item.curr_;
}

std::shared_ptr<std::vector<std::string>>
ConstStrBlobPtr::check(ConstStrBlobPtr::SizeType i,
                       const std::string& msg) const
{
    auto ret{wptr_.lock()};
    if (!ret) {
        throw std::runtime_error{"unbound ConstStrBlobPtr"};
    }
    if (i >= std::size(*ret)) {
        throw std::out_of_range{msg};
    }

    return ret;
}
