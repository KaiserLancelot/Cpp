//
// Created by kaiser on 18-12-23.
//

#include "ex_14_23.h"

#include <algorithm>

StrVec::StrVec(std::initializer_list<std::string> il) {
  auto new_data{AllocCopy(std::begin(il), std::end(il))};
  begin_ = new_data.first;
  end_ = cap_ = new_data.second;
}

StrVec::StrVec(const StrVec &item) {
  auto new_data{AllocCopy(item.begin(), item.end())};
  begin_ = new_data.first;
  end_ = cap_ = new_data.second;
}

StrVec &StrVec::operator=(const StrVec &item) {
  auto new_data{AllocCopy(item.begin(), item.end())};
  Free();
  begin_ = new_data.first;
  end_ = cap_ = new_data.second;
  return *this;
}

StrVec &StrVec::operator=(std::initializer_list<std::string> il) {
  auto new_data{AllocCopy(std::begin(il), std::end(il))};
  Free();
  begin_ = new_data.first;
  end_ = cap_ = new_data.second;
  return *this;
}

StrVec::~StrVec() { Free(); }

void StrVec::PushBack(const std::string &s) {
  CheckAlloc();
  std::allocator_traits<decltype(alloc_)>::construct(alloc_, end_++, s);
}

StrVec::SizeType StrVec::size() const { return end_ - begin_; }

StrVec::SizeType StrVec::Capacity() const { return cap_ - begin_; }

std::string *StrVec::begin() const { return begin_; }

std::string *StrVec::end() const { return end_; }

void StrVec::Reserve(SizeType new_cap) {
  if (new_cap > Capacity()) {
    Reallocate(new_cap);
  }
}

void StrVec::Resize(SizeType new_size) { Resize(new_size, std::string()); }

void StrVec::Resize(StrVec::SizeType new_size, const std::string &value) {
  if (new_size > size()) {
    for (auto i{new_size}; i < size(); ++i)
      PushBack(value);
  } else if (new_size < size()) {
    auto old_end{end_};
    end_ = begin_ + new_size;
    std::destroy(end_, old_end);
  }
}

void StrVec::CheckAlloc() {
  if (size() == Capacity())
    Reallocate(size() ? 2 * size() : 1);
}

std::pair<std::string *, std::string *>
StrVec::AllocCopy(const std::string *begin, const std::string *end) {
  auto data{alloc_.allocate(end - begin)};
  return {data, std::uninitialized_copy(begin, end, data)};
}

void StrVec::Free() {
  if (begin_) {
    std::destroy(begin_, end_);
    alloc_.deallocate(begin_, cap_ - begin_);
  }
}

void StrVec::Reallocate(SizeType new_cap) {
  auto new_begin{alloc_.allocate(new_cap)};
  auto new_end{std::uninitialized_move(begin_, end_, new_begin)};

  Free();

  begin_ = new_begin;
  end_ = new_end;
  cap_ = new_begin + new_cap;
}

bool operator==(const StrVec &lhs, const StrVec &rhs) {
  if (lhs.size() != rhs.size()) {
    return false;
  }

  return std::equal(lhs.begin(), lhs.end(), rhs.begin());
}

bool operator!=(const StrVec &lhs, const StrVec &rhs) { return !(lhs == rhs); }

bool operator<(const StrVec &lhs, const StrVec &rhs) {
  return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(),
                                      rhs.end());
}

bool operator<=(const StrVec &lhs, const StrVec &rhs) {
  return (lhs < rhs) || (lhs == rhs);
}

bool operator>(const StrVec &lhs, const StrVec &rhs) { return !(lhs <= rhs); }

bool operator>=(const StrVec &lhs, const StrVec &rhs) { return !(lhs < rhs); }
