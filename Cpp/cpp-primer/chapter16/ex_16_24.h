//
// Created by kaiser on 19-3-4.
//

#ifndef CPP_PRIMER_EX_16_24_H
#define CPP_PRIMER_EX_16_24_H

#include <initializer_list>
#include <memory>
#include <string>
#include <utility>
#include <vector>

template <typename T>
class BlobPtr;

template <typename T>
class Blob {
  friend BlobPtr<T>;
  //  template <typename T>
  //  friend class BlobPtr;

 public:
  using ValueType = T;
  using SizeType = typename std::vector<T>::size_type;
  Blob();
  Blob(std::initializer_list<T> il);

  template <typename Iterator>
  Blob(Iterator begin, Iterator end);

  BlobPtr<T> begin();
  BlobPtr<T> end();
  SizeType size() const { return std::size(*data_); }
  bool empty() const { return std::empty(*data_); }
  void PushBack(const T& t) { data_->push_back(t); }
  void PushBack(T&& t) { data_->push_back(std::move(t)); }
  void PopBack();
  T& Back();
  T& operator[](SizeType i);

  const T& Back() const;
  const T& operator[](SizeType i) const;

 private:
  void Check(SizeType i, const std::string& msg) const;
  std::shared_ptr<std::vector<T>> data_;
};

template <typename T>
Blob<T>::Blob() : data_{std::make_shared<std::vector<T>>()} {}

template <typename T>
Blob<T>::Blob(std::initializer_list<T> il)
    : data_{std::make_shared<std::vector<T>>(il)} {}

template <typename T>
void Blob<T>::PopBack() {
  Check(0, "PopBack on empty blob");
  return data_->pop_back();
}

template <typename T>
T& Blob<T>::Back() {
  Check(0, "Back on empty blob");
  return data_->back();
}

template <typename T>
T& Blob<T>::operator[](Blob::SizeType i) {
  Check(i, "subscript out of range");
  return (*data_)[i];
}

template <typename T>
void Blob<T>::Check(Blob::SizeType i, const std::string& msg) const {
  if (i >= size()) {
    throw std::out_of_range{msg};
  }
}

template <typename T>
const T& Blob<T>::Back() const {
  Check(0, "Back on empty blob");
  return data_->back();
}

template <typename T>
const T& Blob<T>::operator[](Blob::SizeType i) const {
  Check(i, "subscript out of range");
  return (*data_)[i];
}

template <typename T>
template <typename Iterator>
Blob<T>::Blob(Iterator begin, Iterator end)
    : data_{std::make_shared<std::vector<T>>(begin, end)} {}

template <typename T>
BlobPtr<T> Blob<T>::begin() {
  return BlobPtr<T>{*this};
}

template <typename T>
BlobPtr<T> Blob<T>::end() {
  return BlobPtr<T>{*this, size()};
}

template <typename T>
class BlobPtr {
  template <typename Type>
  friend bool operator==(const BlobPtr<Type>& lhs, const BlobPtr<Type>& rhs);
  template <typename Type>
  friend bool operator!=(const BlobPtr<Type>& lhs, const BlobPtr<Type>& rhs);

 public:
  BlobPtr() = default;
  explicit BlobPtr(Blob<T>& a, std::size_t sz = 0)
      : wptr_{a.data_}, curr_{sz} {}

  T& operator*() const {
    auto p{Check(curr_, "dereference past end")};
    return (*p)[curr_];
  }

  BlobPtr& operator++() {
    Check(curr_, "inc out of range");
    ++curr_;
    return *this;
  }

  BlobPtr& operator--() {
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
  std::shared_ptr<std::vector<T>> Check(std::size_t i,
                                        const std::string& msg) const;
  std::weak_ptr<std::vector<T>> wptr_;
  std::size_t curr_{};
};

template <typename T>
std::shared_ptr<std::vector<T>> BlobPtr<T>::Check(
    std::size_t i, const std::string& msg) const {
  auto p{wptr_.lock()};
  if (!p) {
    throw std::runtime_error{"empty"};
  }
  if (i > std::size(*p)) {
    throw std::out_of_range{msg};
  }
  return p;
}

template <typename Type>
bool operator==(const BlobPtr<Type>& lhs, const BlobPtr<Type>& rhs) {
  return lhs.curr_ == rhs.curr_ && lhs.wptr_.lock() == rhs.wptr_.lock();
}

template <typename Type>
bool operator!=(const BlobPtr<Type>& lhs, const BlobPtr<Type>& rhs) {
  return !(lhs == rhs);
}

#endif  // CPP_PRIMER_EX_16_24_H
