//Malvestio Andrea mat:2032464
#include <iostream>

bool is_palindrome(const std::string& s);

int main(){
	std::cout << is_palindrome("ciao");
	std::cout << is_palindrome("anna");
	
	return 0;
}

bool is_palindrome(const std::string& s)
{
	int i = 0;
	int j = s.size() - 1;
	while(i<j){
		if(s[i] != s[j]) return false;
		i++;
		j--;
	}
	return true;
}