#include <iostream>
#include "Malvestio_Andrea_Lab2.cpp"

int main(){
	Rational r{2,4};
	Rational sos{6,9};
    std::cout << r+20 << "valore razionale: "<< (r+20).to_double();
	return 0;
}

/*
	vector& vector::operator=(const vector& a){
		double* p = new double[a.sz];
		copy(a.elem, a.elem + a.sz, p);
		delete[] this->elem;
		this->elem=p;
		this->sz = a.sz;
		return *this;
}
*/