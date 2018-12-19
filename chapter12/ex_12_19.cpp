//
// Created by kaiser on 18-12-19.
//

#include "ex_12_19.h"

#include <stdexcept>

StrBlob::StrBlob()
        : data_{std::make_shared<std::vector<std::string>>()} {}

StrBlob::StrBlob(std::initializer_list<std::string> il)
        : data_{std::make_shared<std::vector<std::string>>(il)} {}

StrBlobPtr StrBlob::begin() {
    return StrBlobPtr{*this};
}

StrBlobPtr StrBlob::end() {
    return StrBlobPtr{*this, std::size(*data_)};
}

StrBlob::size_type StrBlob::Size() const {
    return std::size(*data_);
}

bool StrBlob::Empty() const {
    return std::empty(*data_);
}

void StrBlob::PushBack(const std::string &t) {
    data_->push_back(t);
}

void StrBlob::PopBack() {
    Check(0, "PopBack on empty StrBlob");
    data_->pop_back();
}

std::string &StrBlob::Front() {
    Check(0, "Front on empty StrBlob");
    return data_->front();
}

std::string &StrBlob::Front() const {
    Check(0, "Front on empty StrBlob");
    return data_->front();
}

std::string &StrBlob::Back() {
    Check(0, "Back on empty StrBlob");
    return data_->back();
}

std::string &StrBlob::Back() const {
    Check(0, "Back on empty StrBlob");
    return data_->back();
}

void StrBlob::Check(StrBlob::size_type i, const std::string &msg) const {
    if (i >= Size()) {
        throw std::out_of_range{msg};
    }
}

StrBlobPtr::StrBlobPtr(StrBlob &a, size_type sz)
        : wptr_{a.data_}, curr_{sz} {}

std::string &StrBlobPtr::Deref() const {
    auto p{Check(curr_, "dereference past end")};
    return (*p)[curr_];
}

StrBlobPtr &StrBlobPtr::Incr() {
    Check(curr_, "increment past end of StrBlobPtr");
    ++curr_;
    return *this;
}

bool StrBlobPtr::NotEqual(const StrBlobPtr &item) const {
    return curr_ != item.curr_;
}

std::shared_ptr<std::vector<std::string>> StrBlobPtr::Check(StrBlobPtr::size_type i, const std::string &msg) const {
    auto ret{wptr_.lock()};
    if (!ret) {
        throw std::runtime_error{"unbound StrBlobPtr"};
    }
    if (i >= std::size(*ret)) {
        throw std::out_of_range{msg};
    }

    return ret;
}
