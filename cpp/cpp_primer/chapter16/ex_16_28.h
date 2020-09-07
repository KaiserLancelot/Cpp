//
// Created by kaiser on 19-3-4.
//

#ifndef CPP_PRIMER_EX_16_28_H
#define CPP_PRIMER_EX_16_28_H

#include <algorithm>
#include <cstdint>
#include <functional>

class Delete {
public:
    template<typename T>
    void operator()(T* ptr) const
    {
        delete ptr;
    }
};

template<typename T>
class SharedPtr;

template<typename Type>
void swap(SharedPtr<Type>& lhs, SharedPtr<Type>& rhs) noexcept;

template<typename T>
class SharedPtr {
    template<typename Type>
    friend void swap(SharedPtr<Type>& lhs, SharedPtr<Type>& rhs) noexcept;

public:
    SharedPtr() : ref_count_{new std::int32_t{}} {}
    explicit SharedPtr(T* ptr) : ptr_{ptr}, ref_count_{new std::int32_t{1}} {}

    SharedPtr(T* ptr, std::function<void(T*)> deleter)
        : ptr_{ptr}, ref_count_{new std::int32_t{1}}, deleter_{deleter} {}

    SharedPtr(const SharedPtr& item)
        : ptr_{item.ptr_}, ref_count_{item.ref_count_}, deleter_{item.deleter_}
    {
        ++*item.ref_count_;
    }

    SharedPtr(SharedPtr&& item) noexcept
        : ptr_{item.ptr_}, ref_count_{item.ref_count_}, deleter_{std::move(
                                                                item.deleter_)}
    {
        item.ptr_ = nullptr;
        item.ref_count_ = nullptr;
    }

    SharedPtr& operator=(SharedPtr item)
    {
        swap(*this, item);
        return *this;
    }

    ~SharedPtr()
    {
        if (--*ref_count_ == 0) {
            deleter_(ptr_);
            delete ref_count_;
        }
    }

    explicit operator bool() const { return ptr_; }

    T& operator*() const { return *ptr_; }

    T* operator->() const { return &operator*(); }

    std::int32_t use_count() const { return *ref_count_; }

    T* get() const { return ptr_; }

    void swap(SharedPtr& item) noexcept { swap(*this, item); }

    void reset() { ~SharedPtr(); }

    void reset(T* ptr)
    {
        ~SharedPtr();
        ptr_ = ptr;
        ref_count_ = new std::int32_t{1};
    }

    void reset(T* ptr, std::function<void(T*)> deleter)
    {
        reset(ptr);
        deleter_ = deleter;
    }

private:
    T* ptr_{};
    std::int32_t* ref_count_{};
    std::function<void(T*)> deleter_{Delete{}};
};

template<typename Type>
void swap(SharedPtr<Type>& lhs, SharedPtr<Type>& rhs) noexcept
{
    using std::swap;
    swap(lhs.ptr_, rhs.ptr_);
    swap(lhs.ref_count_, rhs.ref_count_);
    swap(lhs.deleter_, rhs.deleter_);
}

template<typename T, typename Deleter = Delete>
class UniquePtr;

template<typename Type>
void swap(UniquePtr<Type>& lhs, UniquePtr<Type>& rhs) noexcept;

template<typename T, typename Deleter>
class UniquePtr {
    template<typename Type>
    friend void swap(UniquePtr<Type>& lhs, UniquePtr<Type>& rhs) noexcept;

public:
    UniquePtr() = default;
    explicit UniquePtr(T* ptr) : ptr_{ptr} {}
    UniquePtr(const UniquePtr&) = delete;
    UniquePtr& operator=(const UniquePtr&) = delete;
    UniquePtr(UniquePtr&& item) noexcept : ptr_{item.ptr_}
    {
        item.ptr_ = nullptr;
    }

    UniquePtr& operator=(UniquePtr&& item) noexcept
    {
        if (this != &item) {
            ~UniquePtr();
            swap(*this, item);
        }
        return *this;
    }

    UniquePtr& operator=(std::nullptr_t n)
    {
        ~UniquePtr();
        return *this;
    }

    ~UniquePtr()
    {
        deleter_(ptr_);
        ptr_ = nullptr;
    }

    T* release()
    {
        auto ret{ptr_};
        ptr_ = nullptr;
        return ret;
    }

    explicit operator bool() const { return ptr_; }
    T& operator*() const { return *ptr_; }
    T* operator->() const { return &operator*(); }
    T* get() const { return ptr_; }
    void reset()
    {
        deleter_(ptr_);
        ptr_ = nullptr;
    }
    void reset(T* ptr)
    {
        deleter_(ptr_);
        ptr_ = ptr;
    }

    void swap(UniquePtr& item) noexcept { swap(*this, item); }

private:
    T* ptr_{};
    Deleter deleter_;
};

template<typename Type>
void swap(UniquePtr<Type>& lhs, UniquePtr<Type>& rhs) noexcept
{
    using std::swap;
    swap(lhs.ptr_, rhs.ptr_);
    swap(lhs.deleter_, rhs.deleter_);
}

#endif // CPP_PRIMER_EX_16_28_H
