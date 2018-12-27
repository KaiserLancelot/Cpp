//
// Created by kaiser on 18-12-19.
//

#ifndef CPP_PRIMER_EX_12_22_H
#define CPP_PRIMER_EX_12_22_H

#include <initializer_list>
#include <memory>
#include <string>
#include <vector>

class StrBlobPtr;
class ConstStrBlobPtr;

class StrBlob {
  friend class StrBlobPtr;
  friend class ConstStrBlobPtr;

 public:
  using SizeType = std::vector<std::string>::size_type;
  StrBlob();
  StrBlob(std::initializer_list<std::string> il);
  StrBlobPtr begin();
  StrBlobPtr end();
  ConstStrBlobPtr begin() const;
  ConstStrBlobPtr end() const;
  SizeType size() const;
  bool empty() const;
  void PushBack(const std::string &t);
  void PopBack();
  std::string &Front();
  const std::string &Front() const;
  std::string &Back();
  const std::string &Back() const;
  std::string &At(SizeType index);
  const std::string &At(SizeType index) const;

 private:
  void Check(SizeType i, const std::string &msg) const;
  std::shared_ptr<std::vector<std::string>> data_;
};

class StrBlobPtr {
 public:
  using SizeType = StrBlob::SizeType;
  StrBlobPtr() = default;
  explicit StrBlobPtr(StrBlob &a, SizeType sz = 0);
  std::string &Deref() const;
  StrBlobPtr &Incr();
  bool NotEqual(const StrBlobPtr &item) const;

 private:
  std::shared_ptr<std::vector<std::string>> Check(SizeType i,
                                                  const std::string &msg) const;
  std::weak_ptr<std::vector<std::string>> wptr_;
  SizeType curr_{};
};

class ConstStrBlobPtr {
 public:
  using SizeType = StrBlob::SizeType;
  ConstStrBlobPtr() = default;
  explicit ConstStrBlobPtr(const StrBlob &a, SizeType sz = 0);
  std::string &Deref() const;
  ConstStrBlobPtr &Incr();
  bool NotEqual(const ConstStrBlobPtr &item) const;

 private:
  std::shared_ptr<std::vector<std::string>> Check(SizeType i,
                                                  const std::string &msg) const;
  std::weak_ptr<std::vector<std::string>> wptr_;
  SizeType curr_{};
};

#endif  // CPP_PRIMER_EX_12_22_H
