//Malvestio Andrea mat: 2032464
#include <iostream>

void f();
void f_illegal();
void print_array_lenght(double* a);
void print_reference(const int& var1, const double& var2);
void print_pointer(int* var1, double* var2);

int main(){
	//f();
	const int n = 106;
	double a[n];
	int var1 = 10;
	double var2 = 5.94;
	int* p1 = &var1;
	double* p2 = &var2;
	std::cout << sizeof a<< "\n";
	print_array_lenght(a);
	print_reference(var1,var2);
	print_pointer(p1,p2);
	return 0;
}

//es 1
void f(){
	int v[10];
	int* p = &v[4];
	for(int i=-5;i<6; i++){
		p[i] = std::rand()%30 +1;
	}
	for(int i=-5;i<6; i++){
		std::cout<< p[i] << " ";
	}
}

void f_illegal(){
	int v[10];
	int* p = &v[4];
	int  i=10;
	while(i<30){
		p[i] = i;
		i++;
	}
}

//es 2
void print_array_lenght(double* a){
	std::cout << sizeof a;
}

//es 3
void print_reference(const int& var1, const double& var2){
	std::cout<< "\nvar 1: " << var1;
	std::cout<< "\nvar 2: " << var2 << '\n';
}

void print_pointer(int* var1, double* var2){
	std::cout<< "puntatore var1: " << var1 << " valore: " <<*var1 << '\n';
	std::cout<< "puntatore var2: " << var2<< " valore: " <<*var2 << '\n';
	
}