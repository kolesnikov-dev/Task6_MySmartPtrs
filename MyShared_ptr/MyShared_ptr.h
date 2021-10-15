#pragma once

template<typename T>
class MyShared_ptr {
public:
    MyShared_ptr(T *Ptr) noexcept : rawPtr(Ptr) { PtrsAmount = new long(1); }
    MyShared_ptr(nullptr_t) noexcept : rawPtr(nullptr) { PtrsAmount = nullptr; }
    MyShared_ptr() noexcept : rawPtr(nullptr) { PtrsAmount = nullptr; }
    MyShared_ptr(MyShared_ptr &) noexcept;
    ~MyShared_ptr() noexcept;

    T &operator*() const;
    T *operator->() const noexcept;
    MyShared_ptr &operator=(const MyShared_ptr &) noexcept;
    explicit operator bool() const noexcept;

    void swap(MyShared_ptr &smartPtr) noexcept;
    void reset(T *newRawPtr = nullptr) noexcept;

    bool unique() const;
    long use_count() const;

private:
    T *rawPtr;
    long *PtrsAmount;
};

#include "MyShared_ptr.cpp"