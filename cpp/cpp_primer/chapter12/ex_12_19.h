//
// Created by kaiser on 18-12-19.
//

#pragma once

#include <initializer_list>
#include <memory>
#include <string>
#include <vector>

class StrBlobPtr;

class StrBlob {
    friend class StrBlobPtr;

public:
    using SizeType = std::vector<std::string>::size_type;
    StrBlob();
    StrBlob(std::initializer_list<std::string> il);
    StrBlobPtr begin();
    StrBlobPtr end();
    SizeType size() const;
    bool empty() const;
    void push_back(const std::string& t);
    void pop_back();
    std::string& front();
    std::string& front() const;
    std::string& back();
    std::string& back() const;

private:
    void check(SizeType i, const std::string& msg) const;
    std::shared_ptr<std::vector<std::string>> data_;
};

class StrBlobPtr {
public:
    using SizeType = StrBlob::SizeType;
    StrBlobPtr() = default;
    explicit StrBlobPtr(StrBlob& a, SizeType sz = 0);
    std::string& deref() const;
    StrBlobPtr& incr();
    bool not_equal(const StrBlobPtr& item) const;

private:
    std::shared_ptr<std::vector<std::string>> check(SizeType i,
                                                    const std::string& msg) const;
    std::weak_ptr<std::vector<std::string>> wptr_;
    SizeType curr_{};
};
