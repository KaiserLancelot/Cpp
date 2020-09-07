//
// Created by kaiser on 18-12-23.
//

#ifndef CPP_PRIMER_EX_14_27_H
#define CPP_PRIMER_EX_14_27_H

#include <initializer_list>
#include <memory>
#include <string>
#include <vector>

class StrBlobPtr;
class ConstStrBlobPtr;

class StrBlob {
    friend bool operator==(const StrBlob& lhs, const StrBlob& rhs);
    friend bool operator<(const StrBlob& lhs, const StrBlob& rhs);
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
    void PushBack(const std::string& t);
    void PopBack();
    std::string& Front();
    const std::string& Front() const;
    std::string& Back();
    const std::string& Back() const;
    std::string& At(SizeType index);
    const std::string& At(SizeType index) const;
    std::string& operator[](SizeType index);
    const std::string& operator[](SizeType index) const;

private:
    void Check(SizeType i, const std::string& msg) const;
    std::shared_ptr<std::vector<std::string>> data_;
};

class StrBlobPtr {
    friend bool operator==(const StrBlobPtr& lhs, const StrBlobPtr& rhs);
    friend bool operator<(const StrBlobPtr& lhs, const StrBlobPtr& rhs);

public:
    using SizeType = StrBlob::SizeType;
    StrBlobPtr() = default;
    explicit StrBlobPtr(StrBlob& a, SizeType sz = 0);
    std::string& Deref() const;
    StrBlobPtr& Incr();
    bool NotEqual(const StrBlobPtr& item) const;
    StrBlobPtr& operator++();
    StrBlobPtr& operator--();
    StrBlobPtr operator++(int);
    StrBlobPtr operator--(int);

private:
    std::shared_ptr<std::vector<std::string>> Check(SizeType i,
                                                    const std::string& msg) const;
    std::weak_ptr<std::vector<std::string>> wptr_;
    SizeType curr_{};
};

class ConstStrBlobPtr {
    friend bool operator==(const ConstStrBlobPtr& lhs,
                           const ConstStrBlobPtr& rhs);
    friend bool operator<(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr& rhs);

public:
    using SizeType = StrBlob::SizeType;
    ConstStrBlobPtr() = default;
    explicit ConstStrBlobPtr(const StrBlob& a, SizeType sz = 0);
    const std::string& Deref() const;
    ConstStrBlobPtr& Incr();
    bool NotEqual(const ConstStrBlobPtr& item) const;
    ConstStrBlobPtr& operator++();
    ConstStrBlobPtr& operator--();
    ConstStrBlobPtr operator++(int);
    ConstStrBlobPtr operator--(int);

private:
    std::shared_ptr<std::vector<std::string>> Check(SizeType i,
                                                    const std::string& msg) const;
    std::weak_ptr<std::vector<std::string>> wptr_;
    SizeType curr_{};
};

bool operator==(const StrBlob& lhs, const StrBlob& rhs);
bool operator!=(const StrBlob& lhs, const StrBlob& rhs);
bool operator<(const StrBlob& lhs, const StrBlob& rhs);
bool operator<=(const StrBlob& lhs, const StrBlob& rhs);
bool operator>(const StrBlob& lhs, const StrBlob& rhs);
bool operator>=(const StrBlob& lhs, const StrBlob& rhs);

bool operator==(const StrBlobPtr& lhs, const StrBlobPtr& rhs);
bool operator!=(const StrBlobPtr& lhs, const StrBlobPtr& rhs);
bool operator<(const StrBlobPtr& lhs, const StrBlobPtr& rhs);
bool operator<=(const StrBlobPtr& lhs, const StrBlobPtr& rhs);
bool operator>(const StrBlobPtr& lhs, const StrBlobPtr& rhs);
bool operator>=(const StrBlobPtr& lhs, const StrBlobPtr& rhs);

bool operator==(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr& rhs);
bool operator!=(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr& rhs);
bool operator<(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr& rhs);
bool operator<=(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr& rhs);
bool operator>(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr& rhs);
bool operator>=(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr& rhs);

#endif // CPP_PRIMER_EX_14_27_H
