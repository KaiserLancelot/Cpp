//
// Created by kaiser on 18-12-22.
//

#include "ex_13_50.h"

#include <algorithm>
#include <cstring>
#include <iostream>

String::String(const char* str)
{
    auto new_data{AllocCopy(str, str + std::strlen(str))};
    begin_ = new_data.first;
    end_ = cap_ = new_data.second;
}

String::String(const String& item)
{
    std::cout << "String(const String &item)\n";
    auto new_data{AllocCopy(item.begin(), item.end())};
    begin_ = new_data.first;
    end_ = cap_ = new_data.second;
}

String::String(String&& item) noexcept
    : begin_{item.begin_}, end_{item.end_}, cap_{item.cap_}
{
    std::cout << "String(String &&item)\n";
    item.begin_ = item.end_ = item.cap_ = nullptr;
}

String& String::operator=(String item)
{
    std::cout << "operator=(String item)\n";
    swap(*this, item);
    return *this;
}

String::~String() { Free(); }

void String::PushBack(char ch)
{
    CheckAlloc();
    std::allocator_traits<decltype(alloc_)>::construct(alloc_, end_++, ch);
}

String::SizeType String::Size() const { return end_ - begin_; }

String::SizeType String::Capacity() const { return cap_ - begin_; }

char* String::begin() { return begin_; }

char* String::end() { return end_; }

const char* String::begin() const { return begin_; }

const char* String::end() const { return end_; }

void String::Reserve(String::SizeType new_cap)
{
    if (new_cap > Capacity()) {
        Reallocate(new_cap);
    }
}

void String::Resize(String::SizeType size) { Resize(size, '\0'); }

void String::Resize(String::SizeType size, char value)
{
    if (size > Size()) {
        for (auto i{size}; i < Size(); ++i) {
            PushBack(value);
        }
    }
    else if (size < Size()) {
        auto old_end{end_};
        end_ = begin_ + size;
        std::destroy(end_, old_end);
    }
}

const char* String::CStr() const
{
    std::allocator_traits<decltype(alloc_)>::construct(alloc_, end_, '\0');
    return begin_;
}

void String::CheckAlloc()
{
    if (Size() == Capacity()) {
        Reallocate(Size() ? 2 * Size() : 1);
    }
}

std::pair<char*, char*> String::AllocCopy(const char* begin,
                                          const char* end)
{
    auto new_data{alloc_.allocate(end - begin)};
    return {new_data, std::uninitialized_copy(begin, end, new_data)};
}

void String::Free()
{
    if (begin_) {
        std::destroy(begin_, end_);
        alloc_.deallocate(begin_, cap_ - begin_);
    }
}

void String::Reallocate(String::SizeType new_cap)
{
    auto new_begin{alloc_.allocate(new_cap)};
    auto new_end{std::uninitialized_copy(begin_, end_, new_begin)};

    Free();

    begin_ = new_begin;
    end_ = new_end;
    cap_ = new_begin + new_cap;
}

void swap(String& lhs, String& rhs)
{
    using std::swap;
    swap(lhs.begin_, rhs.begin_);
    swap(lhs.end_, rhs.end_);
    swap(lhs.cap_, rhs.cap_);
}
