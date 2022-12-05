//Malvestio Andrea mat:2032464
#include <iostream>

bool is_palindrome(const char s[], int length);

int main(){
	char c[]{"anna"};
	char v[]{"ciao"};
	std::cout << is_palindrome(c, 4);
	std::cout << is_palindrome(v, 4);
	return 0;
}

bool is_palindrome(const char s[], int length)
{
	int i=0;
	int j= length -1;
	while (i < j)
	{
			if(s[i] != s[j]) return false;
			i++;
			j--;
	}
	return true;
}