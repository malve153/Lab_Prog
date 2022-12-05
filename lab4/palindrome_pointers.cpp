//Malvestio Andrea mat:2032464
#include <iostream>

bool is_palindrome(const char* first, const char* last);

int main(){
	char c[]{"anna"};
	char* f = &c[0];
	char* l = &c[3];
	std::cout << is_palindrome(f , l);
	char v[]{"ciao"};
	char* f1 = &v[0];
	char* l1= &v[3];
	std::cout << is_palindrome(f1 , l1);
	
	return 0;
}

bool is_palindrome(const char* first, const char* last){
	int i=0;
	while(i< (last-first)/2){
		if(first[i] != last[-i]) return false;
		i++;
	}
	return true;
}