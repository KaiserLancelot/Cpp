//
// Created by kaiser on 18-12-21.
//

#ifndef CPP_PRIMER_EX_13_40_H
#define CPP_PRIMER_EX_13_40_H

#include <string>
#include <cstddef>
#include <memory>
#include <utility>
#include <initializer_list>

class StrVec {
 public:
  using SizeType=std::size_t;
  StrVec() = default;
  StrVec(std::initializer_list<std::string> il);
  StrVec(const StrVec &item);
  StrVec &operator=(const StrVec &item);
  ~StrVec();
  void PushBack(const std::string &s);
  SizeType Size() const;
  SizeType Capacity() const;
  std::string *begin() const;
  std::string *end() const;
  void Reserve(SizeType new_cap);
  void Resize(SizeType size);
  void Resize(SizeType size, const std::string &value);
 private:
  void CheckAlloc();
  std::pair<std::string *, std::string *>
  AllocCopy(const std::string *begin, const std::string *end);
  void Free();
  void Reallocate(SizeType new_cap);

  std::string *begin_{};
  std::string *end_{};
  std::string *cap_{};

  inline static std::allocator<std::string> alloc_;
};

#endif //CPP_PRIMER_EX_13_40_H
