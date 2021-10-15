#pragma once

#include <string>

template <typename T>
class MyUnique_ptr
{
public:
    MyUnique_ptr(T *Ptr = nullptr) noexcept : rawPtr(Ptr) {}
    ~MyUnique_ptr() noexcept;

    T &operator*() const;
    T *operator->() const noexcept;
    MyUnique_ptr &operator=(nullptr_t) noexcept;
    explicit operator bool() const noexcept;

    T *get() const noexcept;
    void swap(MyUnique_ptr &smartPtr) noexcept;
    T *release() noexcept;
    void reset(T *newRawPtr = nullptr) noexcept;

    MyUnique_ptr &operator=(const MyUnique_ptr &) = delete;
    MyUnique_ptr(const MyUnique_ptr &) = delete;

private:
    T *rawPtr;
};

#include "MyUnique_ptr.cpp"