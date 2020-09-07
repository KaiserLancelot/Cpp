//
// Created by kaiser on 19-3-4.
//

#ifndef CPP_PRIMER_EX_16_29_H
#define CPP_PRIMER_EX_16_29_H

#include <initializer_list>
#include <string>
#include <utility>
#include <vector>

#include "ex_16_28.h"

template<typename T>
class Blob {
public:
    using ValueType = T;
    using SizeType = typename std::vector<T>::size_type;
    using Iterator = typename std::vector<T>::iterator;
    Blob();
    Blob(std::initializer_list<T> il);

    template<typename Iter>
    Blob(Iter begin, Iter end);

    Iterator begin() { return data_->begin(); }
    Iterator end() { return data_->end(); }
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
    SharedPtr<std::vector<T>> data_;
};

template<typename T>
Blob<T>::Blob() : data_{new std::vector<T>}
{}

template<typename T>
Blob<T>::Blob(std::initializer_list<T> il) : data_{new std::vector<T>(il)}
{}

template<typename T>
void Blob<T>::PopBack()
{
    Check(0, "PopBack on empty blob");
    return data_->pop_back();
}

template<typename T>
T& Blob<T>::Back()
{
    Check(0, "Back on empty blob");
    return data_->back();
}

template<typename T>
T& Blob<T>::operator[](Blob::SizeType i)
{
    Check(i, "subscript out of range");
    return (*data_)[i];
}

template<typename T>
void Blob<T>::Check(Blob::SizeType i, const std::string& msg) const
{
    if (i >= size()) {
        throw std::out_of_range{msg};
    }
}

template<typename T>
const T& Blob<T>::Back() const
{
    Check(0, "Back on empty blob");
    return data_->back();
}

template<typename T>
const T& Blob<T>::operator[](Blob::SizeType i) const
{
    Check(i, "subscript out of range");
    return (*data_)[i];
}

template<typename T>
template<typename Iter>
Blob<T>::Blob(Iter begin, Iter end) : data_{new std::vector<T>(begin, end)}
{}

#endif // CPP_PRIMER_EX_16_29_H
