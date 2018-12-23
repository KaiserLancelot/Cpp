//
// Created by kaiser on 18-12-23.
//

#include "ex_14_07.h"

#include <cstring>

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

void String::Resize(String::SizeType size) {
  Resize(size, '\0');
}

void String::Resize(String::SizeType size, char value) {
  if (size > size()) {
    for (auto i{size}; i < size(); ++i) {
      PushBack(value);
    }
  } else if (size < size()) {
    auto old_end{end_};
    end_ = begin_ + size;
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
