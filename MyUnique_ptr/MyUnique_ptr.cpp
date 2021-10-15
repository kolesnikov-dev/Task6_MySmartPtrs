#include "MyUnique_ptr.h"

#include <iostream>

template <typename T>
MyUnique_ptr<T>::~MyUnique_ptr() noexcept
{
    delete rawPtr;
    rawPtr = nullptr;
}

template <typename T>
T& MyUnique_ptr<T>::operator*() const
{
    if (rawPtr != nullptr)
        return *rawPtr;

    throw std::exception();
}

template <typename T>
T* MyUnique_ptr<T>::operator->() const noexcept
{
    return rawPtr;
}

template <typename T>
MyUnique_ptr<T>& MyUnique_ptr<T>::operator=(nullptr_t) noexcept
{
    reset();
    return *this;
}

template <typename T>
MyUnique_ptr<T>::operator bool() const noexcept
{
    return static_cast<bool>(rawPtr);
}

template <typename T>
T* MyUnique_ptr<T>::get() const noexcept
{
    return rawPtr;
}

template <typename T>
void MyUnique_ptr<T>::swap(MyUnique_ptr &smartPtr) noexcept
{
    this->rawPtr = smartPtr.rawPtr;
    smartPtr.rawPtr = nullptr;
}

template <typename T>
T *MyUnique_ptr<T>::release() noexcept
{
    T *data = nullptr;
    if (rawPtr != nullptr)
    {
        data = new T (*rawPtr);
        rawPtr = nullptr;
    }

    return data;
}

template <typename T>
void MyUnique_ptr<T>::reset(T *newRawPtr) noexcept
{
    delete rawPtr;
    rawPtr = newRawPtr;
}