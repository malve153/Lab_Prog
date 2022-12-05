#include "MyVector.h"

int main() {
	MyVector<double> v1 {3,64,94.3,54,999};
	std::cout << "v1->size: " << v1.getSize() <<"\n";
	std::cout << "v1->max_size: " << v1.getMaxSize() << "\n";
	v1.push_back(45.0);
	v1.push_back(59);
	v1.push_back(104);
	v1.push_back(39);
	v1.push_back(91);
	v1.push_back(42);
	std::cout << "v1: " << v1;
	std::cout << "v1->size: " << v1.getSize() <<"\n";
	std::cout << "v1->max_size: " << v1.getMaxSize() << "\n";
	v1.pop_back();
	std::cout << "v1: " << v1;
	std::cout << "v1->size: " << v1.getSize() <<"\n";
	std::cout << "v1->max_size: " << v1.getMaxSize() << "\n";
	MyVector<double> v2(5);
	v2.safe_set(3, v1.at(2) );
	std::cout << "v2.at(3): " << v2.at(3) << "\n";
	std::cout << "v2.at(2): " << v2.at(2) <<"\n";
	std::cout << "v2: " << v2;
	MyVector<double> v3(2);
	v3 = v1;
	v3.safe_set(3,69);
	std::cout << "v3: " << v3;
	return 0;
}