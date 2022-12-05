//Malvestio Andrea mat: 2032464
#include "MyVector.hpp"

int main() {

	std::cout << "v1: " << std::endl;
	MyVector v1 {3,65,98.4,23,322};
	std::cout << v1 << std::endl;
	MyVector v2(5);

	std::cout << "v1[2] = " << v1[2] << std::endl;

	std::cout << "v2[3] = v1[2]: ";
	v2[3] = v1[2];

	std::cout << "v2[3] = " << v2[3] << std::endl;

	std::cout << "v3 = v1: " << std::endl;
	MyVector v3 = v1;
	std::cout << v3<< std::endl;

	std::cout << "v2 = v3: " << std::endl;
	v2 = v3;
	std::cout << v2 << std::endl;

	return 0;
}