//
// Created by kaiser on 18-12-19.
//

#include "ex_12_02.h"

#include <stdexcept>

StrBlob::StrBlob()
    : data_{std::make_shared < std::vector < std::string >> ()} {}

StrBlob::StrBlob(std::initializer_list<std::string> il)
    : data_{std::make_shared < std::vector < std::string >> (il)} {}

StrBlob::size_type StrBlob::size() const {
  return std::size(*data_);
}

bool StrBlob::empty() const {
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
