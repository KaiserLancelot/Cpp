//
// Created by kaiser on 18-12-20.
//

#include "ex_13_26.h"

#include <stdexcept>

StrBlob::StrBlob() : data_{std::make_shared<std::vector<std::string>>()} {}

StrBlob::StrBlob(const StrBlob &item)
    : data_{std::make_shared<std::vector<std::string>>(*item.data_)} {}

StrBlob &StrBlob::operator=(const StrBlob &item) {
  data_ = std::make_shared<std::vector<std::string>>(*item.data_);
  return *this;
}

StrBlob::StrBlob(std::initializer_list<std::string> il)
    : data_{std::make_shared<std::vector<std::string>>(il)} {}

StrBlobPtr StrBlob::begin() { return StrBlobPtr{*this}; }

StrBlobPtr StrBlob::end() { return StrBlobPtr{*this, std::size(*data_)}; }

ConstStrBlobPtr StrBlob::begin() const { return ConstStrBlobPtr{*this}; }
ConstStrBlobPtr StrBlob::end() const {
  return ConstStrBlobPtr{*this, std::size(*data_)};
}

StrBlob::SizeType StrBlob::Size() const { return std::size(*data_); }

bool StrBlob::Empty() const { return std::empty(*data_); }

void StrBlob::PushBack(const std::string &t) { data_->push_back(t); }

void StrBlob::PopBack() {
  Check(0, "PopBack on empty StrBlob");
  data_->pop_back();
}

std::string &StrBlob::Front() {
  Check(0, "Front on empty StrBlob");
  return data_->front();
}

const std::string &StrBlob::Front() const {
  Check(0, "Front on empty StrBlob");
  return data_->front();
}

std::string &StrBlob::Back() {
  Check(0, "Back on empty StrBlob");
  return data_->back();
}

const std::string &StrBlob::Back() const {
  Check(0, "Back on empty StrBlob");
  return data_->back();
}

std::string &StrBlob::At(SizeType index) { return data_->at(index); }

const std::string &StrBlob::At(SizeType index) const {
  return data_->at(index);
}

void StrBlob::Check(StrBlob::SizeType i, const std::string &msg) const {
  if (i >= Size()) {
    throw std::out_of_range{msg};
  }
}

StrBlobPtr::StrBlobPtr(StrBlob &a, size_type sz) : wptr_{a.data_}, curr_{sz} {}

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

std::shared_ptr<std::vector<std::string>>
StrBlobPtr::Check(StrBlobPtr::size_type i, const std::string &msg) const {
  auto ret{wptr_.lock()};
  if (!ret) {
    throw std::runtime_error{"unbound StrBlobPtr"};
  }
  if (i >= std::size(*ret)) {
    throw std::out_of_range{msg};
  }

  return ret;
}

ConstStrBlobPtr::ConstStrBlobPtr(const StrBlob &a,
                                 ConstStrBlobPtr::size_type sz)
    : wptr_{a.data_}, curr_{sz} {}

std::string &ConstStrBlobPtr::Deref() const {
  auto p{Check(curr_, "dereference past end")};
  return (*p)[curr_];
}

ConstStrBlobPtr &ConstStrBlobPtr::Incr() {
  Check(curr_, "increment past end of StrBlobPtr");
  ++curr_;
  return *this;
}

bool ConstStrBlobPtr::NotEqual(const ConstStrBlobPtr &item) const {
  return curr_ != item.curr_;
}

std::shared_ptr<std::vector<std::string>>
ConstStrBlobPtr::Check(ConstStrBlobPtr::size_type i,
                       const std::string &msg) const {
  auto ret{wptr_.lock()};
  if (!ret) {
    throw std::runtime_error{"unbound ConstStrBlobPtr"};
  }
  if (i >= std::size(*ret)) {
    throw std::out_of_range{msg};
  }

  return ret;
}
