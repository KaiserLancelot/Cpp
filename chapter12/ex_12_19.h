//
// Created by kaiser on 18-12-19.
//

#ifndef CPP_PRIMER_EX_12_19_H
#define CPP_PRIMER_EX_12_19_H

#include <vector>
#include <string>
#include <memory>
#include <initializer_list>

class StrBlobPtr;

class StrBlob {
    friend class StrBlobPtr;
public:
    using size_type=std::vector<std::string>::size_type;
    StrBlob();
    StrBlob(std::initializer_list<std::string> il);
    StrBlobPtr begin();
    StrBlobPtr end();
    size_type Size() const;
    bool Empty() const;
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

class StrBlobPtr {
public:
    using size_type=StrBlob::size_type;
    StrBlobPtr() = default;
    explicit StrBlobPtr(StrBlob &a, size_type sz = 0);
    std::string &Deref() const;
    StrBlobPtr &Incr();
    bool NotEqual(const StrBlobPtr &item) const;
private:
    std::shared_ptr<std::vector<std::string>>
    Check(size_type i, const std::string &msg) const;
    std::weak_ptr<std::vector<std::string>> wptr_;
    size_type curr_{};
};

#endif //CPP_PRIMER_EX_12_19_H
