#include "MyShared_ptr.h"

template <typename T>
MyShared_ptr<T>::MyShared_ptr(MyShared_ptr &smartPtr) noexcept
{
    if (smartPtr.PtrsAmount != nullptr)
        (*smartPtr.PtrsAmount)++;

    this->PtrsAmount = smartPtr.PtrsAmount;
    this->rawPtr = smartPtr.rawPtr;
}

template <typename T>
MyShared_ptr<T>::~MyShared_ptr() noexcept
{
    if (PtrsAmount != nullptr)
    {
        if (*PtrsAmount == 1)
        {
            delete rawPtr;
            delete PtrsAmount;
        }
        else
            (*PtrsAmount)--;
    }
}

template <typename T>
T &MyShared_ptr<T>::operator*() const
{
    if (rawPtr != nullptr)
        return *rawPtr;

    throw std::exception();
}

template <typename T>
T *MyShared_ptr<T>::operator->() const noexcept
{
    return rawPtr;
}

template <typename T>
MyShared_ptr<T> &MyShared_ptr<T>::operator=(const MyShared_ptr &smartPtr) noexcept
{
    if (smartPtr.PtrsAmount != nullptr)
        (*smartPtr.PtrsAmount)++;

    if (this->PtrsAmount != nullptr)
    {
        if (*(this->PtrsAmount) == 1)
        {
            delete PtrsAmount;
            delete rawPtr;
        }
        else
            (*this->PtrsAmount)--;
    }
    this->PtrsAmount = smartPtr.PtrsAmount;
    this->rawPtr = smartPtr.rawPtr;

    return *this;
}

template <typename T>
MyShared_ptr<T>::operator bool() const noexcept
{
    return static_cast<bool>(rawPtr);
}

template <typename T>
void MyShared_ptr<T>::swap(MyShared_ptr &smartPtr) noexcept
{
    T *bufRawPtr = this->rawPtr;
    this->rawPtr = smartPtr.rawPtr;
    smartPtr.rawPtr = bufRawPtr;

    long *bufPtrsAmount = this->PtrsAmount;
    this->PtrsAmount = smartPtr.PtrsAmount;
    smartPtr.PtrsAmount = bufPtrsAmount;
}

template <typename T>
void MyShared_ptr<T>::reset(T *newRawPtr) noexcept
{
    if (PtrsAmount != nullptr)
    {
        if (*PtrsAmount == 1)
        {
            delete rawPtr;
            delete PtrsAmount;
            rawPtr = nullptr;
            PtrsAmount = nullptr;
        }
        else
        {
            rawPtr = nullptr;
            (*PtrsAmount)--;
            PtrsAmount = nullptr;
        }
    }
}

template <typename T>
bool MyShared_ptr<T>::unique() const
{
    if (PtrsAmount != nullptr)
        return (*PtrsAmount == 1);

    throw std::exception();
}

template <typename T>
long MyShared_ptr<T>::use_count() const
{
    if (PtrsAmount != nullptr)
        return *PtrsAmount;

    throw std::exception();
}