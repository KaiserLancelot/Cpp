//
// Created by kaiser on 18-12-23.
//

#include "ex_14_18_string.h"

#include <cstring>
#include <algorithm>

String::String(const char *str) {
  auto new_data{AllocCopy(str, str + std::strlen(str))};
  begin_ = new_data.first;
  end_ = cap_ = new_data.second;
}

String::String(const String &item) {
  auto new_data{AllocCopy(item.begin(), item.end())};
  begin_ = new_data.first;
  end_ = cap_ = new_data.second;
}

String &String::operator=(const String &item) {
  auto new_data{AllocCopy(item.begin(), item.end())};
  Free();
  begin_ = new_data.first;
  end_ = cap_ = new_data.second;
  return *this;
}

String::~String() {
  Free();
}

void String::PushBack(char ch) {
  CheckAlloc();
  std::allocator_traits<decltype(alloc_)>::construct(alloc_, end_++, ch);
}

String::SizeType String::size() const {
  return end_ - begin_;
}

String::SizeType String::Capacity() const {
  return cap_ - begin_;
}

char *String::begin() {
  return begin_;
}

char *String::end() {
  return end_;
}

const char *String::begin() const {
  return begin_;
}

const char *String::end() const {
  return end_;
}

void String::Reserve(String::SizeType new_cap) {
  if (new_cap > Capacity()) {
    Reallocate(new_cap);
  }
}

void String::Resize(String::SizeType new_size) {
  Resize(new_size, '\0');
}

void String::Resize(String::SizeType new_size, char value) {
  if (new_size > size()) {
    for (auto i{new_size}; i < size(); ++i) {
      PushBack(value);
    }
  } else if (new_size < size()) {
    auto old_end{end_};
    end_ = begin_ + new_size;
    std::destroy(end_, old_end);
  }
}

const char *String::CStr() const {
  std::allocator_traits<decltype(alloc_)>::construct(alloc_, end_, '\0');
  return begin_;
}

void String::CheckAlloc() {
  if (size() == Capacity()) {
    Reallocate(size() ? 2 * size() : 1);
  }
}

std::pair<char *, char *> String::AllocCopy(const char *begin, const char *end) {
  auto new_data{alloc_.allocate(end - begin)};
  return {new_data, std::uninitialized_copy(begin, end, new_data)};
}

void String::Free() {
  if (begin_) {
    std::destroy(begin_, end_);
    alloc_.deallocate(begin_, cap_ - begin_);
  }
}

void String::Reallocate(String::SizeType new_cap) {
  auto new_begin{alloc_.allocate(new_cap)};
  auto new_end{std::uninitialized_copy(begin_, end_, new_begin)};

  Free();

  begin_ = new_begin;
  end_ = new_end;
  cap_ = new_begin + new_cap;
}

std::ostream &operator<<(std::ostream &os, const String &s) {
  os << s.CStr();
  return os;
}

bool operator==(const String &lhs, const String &rhs) {
  if (lhs.size() != rhs.size()) {
    return false;
  }

  return std::equal(lhs.begin(), lhs.end(), rhs.begin());
}

bool operator!=(const String &lhs, const String &rhs) {
  return !(lhs == rhs);
}

bool operator<(const String &lhs, const String &rhs) {
  return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

bool operator<=(const String &lhs, const String &rhs) {
  return (lhs < rhs) || (lhs == rhs);
}

bool operator>(const String &lhs, const String &rhs) {
  return !(lhs <= rhs);
}

bool operator>=(const String &lhs, const String &rhs) {
  return !(lhs < rhs);
}
