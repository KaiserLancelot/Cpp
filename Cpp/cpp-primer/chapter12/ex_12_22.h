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
  void push_back(const std::string &t);
  void pop_back();
  std::string &front();
  const std::string &front() const;
  std::string &back();
  const std::string &back() const;
  std::string &at(SizeType index);
  const std::string &at(SizeType index) const;

 private:
  void check(SizeType i, const std::string &msg) const;
  std::shared_ptr<std::vector<std::string>> data_;
};

class StrBlobPtr {
 public:
  using SizeType = StrBlob::SizeType;
  StrBlobPtr() = default;
  explicit StrBlobPtr(StrBlob &a, SizeType sz = 0);
  std::string &deref() const;
  StrBlobPtr &incr();
  bool not_equal(const StrBlobPtr &item) const;

 private:
  std::shared_ptr<std::vector<std::string>> check(SizeType i,
                                                  const std::string &msg) const;
  std::weak_ptr<std::vector<std::string>> wptr_;
  SizeType curr_{};
};

class ConstStrBlobPtr {
 public:
  using SizeType = StrBlob::SizeType;
  ConstStrBlobPtr() = default;
  explicit ConstStrBlobPtr(const StrBlob &a, SizeType sz = 0);
  std::string &deref() const;
  ConstStrBlobPtr &incr();
  bool not_equal(const ConstStrBlobPtr &item) const;

 private:
  std::shared_ptr<std::vector<std::string>> check(SizeType i,
                                                  const std::string &msg) const;
  std::weak_ptr<std::vector<std::string>> wptr_;
  SizeType curr_{};
};

#endif  // CPP_PRIMER_EX_12_22_H
