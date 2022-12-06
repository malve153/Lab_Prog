#include <iostream>
#include "Malvestio_Andrea_Lab2.cpp"

int main(){
	Rational r{2,4};
	Rational sos{6,9};
    std::cout << r+20 << "valore razionale: "<< (r+20).to_double();
	return 0;
}