//Malvestio Andrea mat:2032464
#include "Link.h"

Link* Link::insert(Link* n) //insert before this
{
    Link* p = this;
    if(n == nullptr) return p;
    n->succ = p;
	if(p->prev){
        p->prev->succ = n;
	}
	n->prev = p->prev;
	p->prev = n;
    return n;
}

Link* Link::add(Link* n) //insert after this
{
    Link* p = this;
    if(n == nullptr) return p;
    n->prev = p;
    if(p->succ)
        p->succ->prev = n;
    n->succ = p->succ;
    p->succ = n;
    return n;
}

Link* Link::erase() //erase this
{
    if(!this) return nullptr;
    Link* p = new Link{};
    if(this->succ) {
        this->succ->prev = this->prev;
        p->value = this->succ->value;
        p->prev = this->succ->prev;
        p->succ = this->succ->succ;
    }
    if(this->prev) {
        this->prev->succ = this->succ;
        p->succ = this->prev->succ;
    }
    free(this);
    return p; 
}

const Link* Link::find (const std::string& s) const //finds string s in the linked list
{
    const Link* p=this;
    while(p)
    {
        if(p->value == s) return p;
        p = p->succ;
    }
    return nullptr;
}

Link* Link::advance(int n) //advance n positions from this
{
    Link* p = this;
    if(!p) return nullptr;
    if(0<n)
    {
        while (n--)
        {
            if(!p->succ) return nullptr;
            p = p->succ;
        }
    }
    else if (n < 0)
    {
        while (n++)
        {
            if(!p->prev) return nullptr;
            p = p->prev;
        }  
    }
    return p;
}

void Link::print_all() //print all the elements of the list
{
	Link* p = this;
    std::cout << "[";
    while (p)
    {
        std::cout << p->value;
        if(p = p->succ) std::cout << ", ";
    }
    std::cout << "]\n";
}

void Link::push_back(Link* n) //add element at the end of the list
{
	Link* p= this;
	if(n != nullptr){
		while(p->succ){
			p= p->succ;
		}
		p->succ = n;
		n->prev = p;
	}
}

Link* Link::push_front(Link* n) //add element at the beginning of the list
{
	if(n == nullptr ) return this;
	this->prev = n;
	n->succ = this;
	return n;
}

Link* Link::pop_back() //revomes the last element of the list
{
    Link* p = this;
    if(this == nullptr) return this;
    while(p->succ){
		p = p->succ;
	}
    p->prev->succ = nullptr;
    p->prev = nullptr;
    return p;
}

Link* Link::pop_front() //removes the first element of the list
{
    Link* tmp = new Link{this->value};
    Link* p = this;
    if(p != nullptr) {
        p = p->erase();
    }
    tmp->print_all();
    delete tmp;
    return p;
}