#include <iostream>
#include "UniquePtr.h"
int main()
{
    int i = 9;
    int* ptr = &i;
    UniquePtr p(ptr);
    int n = *p;
    std::cout<< "valore n: "<<n<<'\n';
    int* ptr1 = p.operator->();
    std::cout<< "valore ptr1: "<<*ptr1<<'\n';
    int* ptr2 = p.release();
    std::cout<< "valore ptr2: "<<*ptr2<<'\n';
    return 0;
}