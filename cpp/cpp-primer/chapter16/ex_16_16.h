//
// Created by kaiser on 19-3-3.
//

#ifndef CPP_PRIMER_EX_16_16_H
#define CPP_PRIMER_EX_16_16_H

#include <cstddef>
#include <initializer_list>
#include <memory>
#include <string>
#include <utility>

template <typename T> class Vec {
public:
  using SizeType = std::size_t;
  Vec() = default;
  Vec(std::initializer_list<T> il);
  Vec(const Vec &item);
  Vec &operator=(const Vec &item);
  ~Vec() { Free(); }
  void PushBack(const T &s);
  SizeType size() const { return end_ - begin_; }
  SizeType Capacity() const { return cap_ - begin_; }
  T *begin() const { return begin_; }
  T *end() const { return end_; }
  void Reserve(SizeType new_cap);
  void Resize(SizeType new_size);
  void Resize(SizeType new_size, const T &value);

private:
  void CheckAlloc();
  std::pair<T *, T *> AllocCopy(const T *begin, const T *end);
  void Free();
  void Reallocate(SizeType new_cap);

  T *begin_{};
  T *end_{};
  T *cap_{};

  inline static std::allocator<T> alloc_;
};

template <typename T> Vec<T>::Vec(std::initializer_list<T> il) {
  auto data{AllocCopy(std::begin(il), std::end(il))};
  begin_ = data.first;
  end_ = cap_ = data.second;
}

template <typename T> Vec<T>::Vec(const Vec &item) {
  auto data{AllocCopy(std::begin(item), std::end(item))};
  begin_ = data.first;
  end_ = cap_ = data.second;
}

template <typename T> Vec<T> &Vec<T>::operator=(const Vec &item) {
  auto data{AllocCopy(std::begin(item), std::end(item))};
  Free();
  begin_ = data.first;
  end_ = cap_ = data.second;
  return *this;
}

template <typename T> void Vec<T>::PushBack(const T &s) {
  CheckAlloc();
  std::allocator_traits<decltype(alloc_)>::construct(alloc_, end_++, s);
}

template <typename T> void Vec<T>::Reserve(Vec::SizeType new_cap) {
  if (new_cap > Capacity()) {
    Reallocate(new_cap);
  }
}

template <typename T> void Vec<T>::Resize(Vec::SizeType new_size) {
  Resize(new_size, T{});
}

template <typename T>
void Vec<T>::Resize(Vec::SizeType new_size, const T &value) {
  if (new_size < size()) {
    std::destroy(begin_ + new_size, end_);
    end_ = begin_ + new_size;
  } else if (new_size > size()) {
    while (new_size > size()) {
      PushBack(value);
    }
  }
}

template <typename T> void Vec<T>::CheckAlloc() {
  if (size() == Capacity()) {
    Reallocate(Capacity() ? 2 * Capacity() : 1);
  }
}

template <typename T>
std::pair<T *, T *> Vec<T>::AllocCopy(const T *begin, const T *end) {
  auto data{alloc_.allocate(end - begin)};
  return {data, std::uninitialized_copy(begin, end, data)};
}

template <typename T> void Vec<T>::Free() {
  if (begin_) {
    std::destroy(begin_, end_);
    alloc_.deallocate(begin_, cap_ - begin_);
  }
}

template <typename T> void Vec<T>::Reallocate(Vec::SizeType new_cap) {
  auto new_begin{alloc_.allocate(new_cap)};
  auto new_end{std::uninitialized_move(begin_, end_, new_begin)};
  Free();
  begin_ = new_begin;
  end_ = new_end;
  cap_ = begin_ + new_cap;
}

#endif // CPP_PRIMER_EX_16_16_H
