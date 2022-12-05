//Malvestio Andrea mat: 2032464
#ifndef MYVECTOR
#define MYVECTOR

#include <iostream>

class MyVector{
public:
    MyVector(std::initializer_list<double> list);
    MyVector(size_t s);
    MyVector(MyVector& vec);
    MyVector(MyVector&& vec);
    ~MyVector();

    MyVector& operator=(const MyVector& vec);
    MyVector& operator=(MyVector&& vec);
    double& operator[](int n);
    double operator[](int n) const;
    friend std::ostream& operator<<(std::ostream& os, MyVector& vec);
    bool safe_set(unsigned int n, double value);
    double safe_get(unsigned int n) const;
    size_t getSize() const {return size;}

private:
    size_t size;
    double* elem;

};

std::ostream& operator<<(std::ostream& os, MyVector& vec);

class OutOfBoundsException : std::exception {
public:
    OutOfBoundsException(std::string t);

    std::string printError();

private:
    std::string message;

};

#endif