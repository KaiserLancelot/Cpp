//
// Created by kaiser on 18-12-19.
//

#ifndef CPP_PRIMER_EX_12_02_H
#define CPP_PRIMER_EX_12_02_H

#include <vector>
#include <string>
#include <memory>
#include <initializer_list>

class StrBlob {
 public:
  using size_type=std::vector<std::string>::size_type;
  StrBlob();
  StrBlob(std::initializer_list<std::string> il);
  size_type size() const;
  bool empty() const;
  void PushBack(const std::string &t);
  void PopBack();
  std::string &Front();
  std::string &Front() const;
  std::string &Back();
  std::string &Back() const;
 private:
  void Check(size_type i, const std::string &msg) const;
  std::shared_ptr<std::vector<std::string>> data_;
};

#endif //CPP_PRIMER_EX_12_02_H
