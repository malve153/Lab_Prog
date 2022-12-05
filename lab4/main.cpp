//Malvestio Andrea mat:2032464
#include "Link.h"

int main(){
    Link* gods = new Link{"thor", nullptr, nullptr};
    gods = gods->insert(new Link{"odin"});
    gods->advance(1)->add(new Link{"poseidon"});
    gods->add(new Link{"hades"});
    
    gods->print_all();
    std::cout <<gods->find("odin")->value << "\n";
    gods = gods->erase();
    gods->print_all();
    gods->push_back(new Link{"athena"});
    gods = gods->push_front(new Link{"aphrodite"});
    gods->print_all();
    Link* p = gods->pop_back();
    std::string s = p->value;
    std::cout << s << std::endl;
    delete p;
    p = nullptr;
    gods->print_all();
    gods = gods->pop_front();
    gods->print_all();
    gods = gods->push_front(new Link{"Loki"});
    gods = gods->push_front(new Link{"Tyr"});
    gods = gods->push_front(new Link{"Freyja"});
    gods->print_all();
    gods->advance(1)->erase();
    gods->print_all();
    gods->advance(4)->erase();
    gods->print_all();
    return 0;
}