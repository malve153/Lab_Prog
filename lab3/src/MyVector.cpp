//Malvestio Andrea mat: 2032464
#include "MyVector.hpp"

MyVector::MyVector(std::initializer_list<double> l)
:size{ l.size() }
{
	this->elem = new double[size];
	std::copy(l.begin(), l.end(), elem);
}

MyVector::MyVector(size_t s){
	this->size = s;
	this->elem = new double[s];
}

MyVector::MyVector(MyVector& vec)
	: size{vec.size}
{
	this->elem = new double[size];
	std::copy(vec.elem, vec.elem + this->size, this->elem);  
}

MyVector::MyVector(MyVector&& vec)
	: size{vec.size}, elem{vec.elem}
{
	vec.size = 0;
	vec.elem = nullptr;
}

MyVector::~MyVector()
{
	delete[] this->elem;
}

MyVector& MyVector::operator=(const MyVector& vec)
{
	double* p = new double [vec.size];
	std::copy(vec.elem, vec.elem + vec.size , p);
	delete[] elem;
	elem = p;
	size = vec.size;
	return *this;
}

MyVector& MyVector::operator=(MyVector&& vec){
	delete[] elem;
	elem = vec.elem;
	size = vec.size;
	vec.elem = nullptr;
	vec.size = 0;
	return *this;
}

double& MyVector::operator[](int n)
{
	return elem[n];
}

double MyVector::operator[](int n) const
{
	return elem[n];
}

std::ostream& operator<<(std::ostream& os, MyVector& vec)
{
	os << "[ ";
	for(int i=0; i< vec.size; i++){
		os << vec[i] << " ";
	}
	os << "]";
	return os;
}

double MyVector::safe_get(unsigned int n) const
{
	if(n < this->size) return elem[n];
	else{
		throw OutOfBoundsException(std::to_string(n));
		return 0;
	}
}

bool MyVector::safe_set(unsigned int n, double value)
{
	if(n < this->size -1){
		elem[n] = value;
		return true;
	}
	else{
		throw OutOfBoundsException(std::to_string(n));
		return false;
	}
}

OutOfBoundsException::OutOfBoundsException(std::string s)
	:message{s} {}

std::string OutOfBoundsException::printError()
{
	return message;
}