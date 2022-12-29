#ifndef UNIQUEPTR_HPP
#define UNIQUEPTR_HPP

template <typename T>
UniquePtr<T>::UniquePtr(T* p) : ptr{p}{}

template <typename T>
T UniquePtr<T>::operator*(){
    return (*ptr);
}

template <typename T>
T* UniquePtr<T>::release()
{
    T* p {ptr};
    ptr = nullptr;
    return p;
}
#endif