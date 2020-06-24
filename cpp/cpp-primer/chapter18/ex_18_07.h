//
// Created by kaiser on 19-3-14.
//

#ifndef CPP_PRIMER_EX_18_07_H
#define CPP_PRIMER_EX_18_07_H

#include <initializer_list>
#include <iostream>
#include <memory>
#include <string>
#include <utility>
#include <vector>

template <typename T> class BlobPtr;

template <typename T> class Blob {
  friend BlobPtr<T>;
  //  template <typename T>
  //  friend class BlobPtr;

public:
  using ValueType = T;
  using SizeType = typename std::vector<T>::size_type;
  Blob();
  Blob(std::initializer_list<T> il);
  SizeType size() const { return std::size(*data_); }
  bool empty() const { return std::empty(*data_); }
  void PushBack(const T &t) { data_->push_back(t); }
  void PushBack(T &&t) { data_->push_back(std::move(t)); }
  void PopBack();
  T &Back();
  T &operator[](SizeType i);

  const T &Back() const;
  const T &operator[](SizeType i) const;

private:
  void Check(SizeType i, const std::string &msg) const;
  std::shared_ptr<std::vector<T>> data_;
};

template <typename T> Blob<T>::Blob() try : data_ {
  std::make_shared<std::vector<T>>()
}
{}
catch (const std::bad_alloc &e) {
  std::cerr << e.what() << '\n';
}

template <typename T> Blob<T>::Blob(std::initializer_list<T> il) try : data_ {
  std::make_shared<std::vector<T>>(il)
}
{}
catch (const std::bad_alloc &e) {
  std::cerr << e.what() << '\n';
}

template <typename T> void Blob<T>::PopBack() {
  Check(0, "PopBack on empty blob");
  return data_->pop_back();
}

template <typename T> T &Blob<T>::Back() {
  Check(0, "Back on empty blob");
  return data_->back();
}

template <typename T> T &Blob<T>::operator[](Blob::SizeType i) {
  Check(i, "subscript out of range");
  return (*data_)[i];
}

template <typename T>
void Blob<T>::Check(Blob::SizeType i, const std::string &msg) const {
  if (i >= size()) {
    throw std::out_of_range{msg};
  }
}

template <typename T> const T &Blob<T>::Back() const {
  Check(0, "Back on empty blob");
  return data_->back();
}

template <typename T> const T &Blob<T>::operator[](Blob::SizeType i) const {
  Check(i, "subscript out of range");
  return (*data_)[i];
}

template <typename T> class BlobPtr {
public:
  BlobPtr() = default;
  explicit BlobPtr(Blob<T> &a, std::size_t sz = 0)
      : wptr_{a.data_}, curr_{sz} {}

  T &operator*() const {
    auto p{Check(curr_, "dereference past end")};
    return (*p)[curr_];
  }

  BlobPtr &operator++() {
    Check(curr_, "inc out of range");
    ++curr_;
    return *this;
  }

  BlobPtr &operator--() {
    --curr_;
    Check(curr_, "dec out of range");
    return *this;
  }

  BlobPtr operator++(int) {
    auto ret{*this};
    ++*this;
    return ret;
  }

  BlobPtr operator--(int) {
    auto ret{*this};
    --*this;
    return ret;
  }

private:
  std::weak_ptr<std::vector<T>> Check(std::size_t i,
                                      const std::string &msg) const {
    auto p{wptr_.lock()};
    if (!p) {
      throw std::runtime_error{"empty"};
    }
    if (i > std::size(*p)) {
      throw std::out_of_range{msg};
    }
    return p;
  }
  std::weak_ptr<std::vector<T>> wptr_;
  std::size_t curr_{};
};

#endif // CPP_PRIMER_EX_18_07_H
