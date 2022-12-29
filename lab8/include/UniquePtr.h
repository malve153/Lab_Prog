#ifndef UNIQUEPTR_H
#define UNIQUEPTR_H


template <typename T> class UniquePtr
{
public:
    UniquePtr(T* p);
    T operator*();
    T* operator->() { return ptr; };
    T* release();
    ~UniquePtr() { delete ptr; };

private:
    T* ptr;
};

#include "UniquePtr.hpp"
#endif