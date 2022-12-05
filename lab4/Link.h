//Malvestio Andrea mat:2032464
#ifndef LINK
#define LINK
#include <iostream>

class Link{
public:
	std::string value;
	
	Link(const std::string& v="", Link* p = nullptr, Link* s = nullptr)
		: value{v}, prev{p}, succ{s} {}
	Link* insert(Link* n);
	Link* add(Link* n);
	Link* erase();
	const Link* find(const std::string& s) const;
	Link* advance(int n);
	void print_all();
	void push_back(Link* n);
	Link* push_front(Link* n);
	Link* pop_back();
	Link* pop_front();
	Link* next() const { return succ; }
	Link* previous() const { return prev; }

	~Link(){ delete prev; delete succ;}

private:
	Link* prev;
	Link* succ;
};

#endif