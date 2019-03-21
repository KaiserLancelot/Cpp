//
// Created by kaiser on 18-12-22.
//

#ifndef CPP_PRIMER_EX_13_50_H
#define CPP_PRIMER_EX_13_50_H

#include <cstddef>
#include <memory>
#include <string>
#include <utility>

class String {
  friend void swap(String &lhs, String &rhs);

 public:
  using SizeType = std::size_t;
  String() = default;
  String(const char *str);
  String(const String &item);
  String(String &&item) noexcept;
  String &operator=(String item);
  ~String();
  void PushBack(char ch);
  SizeType Size() const;
  SizeType Capacity() const;
  char *begin();
  char *end();
  const char *begin() const;
  const char *end() const;
  void Reserve(SizeType new_cap);
  void Resize(SizeType size);
  void Resize(SizeType size, char value);
  const char *CStr() const;

 private:
  void CheckAlloc();
  std::pair<char *, char *> AllocCopy(const char *begin, const char *end);
  void Free();
  void Reallocate(SizeType new_cap);

  char *begin_{};
  char *end_{};
  char *cap_{};

  inline static std::allocator<char> alloc_;
};

void swap(String &lhs, String &rhs);

#endif  // CPP_PRIMER_EX_13_50_H
