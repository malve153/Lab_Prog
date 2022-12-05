//Malvestio Andrea mat: 2032464
#ifndef MYVECTOR
#define MYVECTOR
#include <iostream>

template<typename T> class MyVector;
template<typename T> std::ostream& operator<<(std::ostream& os,const MyVector<T>& vec);

template<typename T>
class MyVector{
public:
	MyVector(std::initializer_list<T> list);
	MyVector(size_t s);
	MyVector(MyVector& vec);
	MyVector(MyVector&& vec);

	~MyVector() { delete[] this->elem; };

	MyVector& operator=(const MyVector& vec);
	MyVector& operator=(MyVector&& vec);
	T& operator[](int n) { return elem[n]; };
	T operator[](int n) const { return elem[n]; }

	T& at(int n);
	T at(int n) const;

	void reserve(size_t n);

	void push_back(T n);
	MyVector& pop_back();

	size_t getSize() const { return size;}
	size_t getMaxSize() const { return max_size; }
	bool safe_set(unsigned int n, T value);
	T safe_get(unsigned int n) const;

private:
	size_t max_size = 10;
	size_t size = 0;
	T* elem;
};



class OutOfBoundsException : std::exception {
public:
	OutOfBoundsException(std::string t);

	std::string printError();

private:
	std::string message;

};

#include "MyVector.hpp"
#endif