#ifndef ELEMENTO_H
#define ELEMENTO_H

#include <cassert>
#include <iostream>

using std::ostream;
using std::string;


class Elemento{
    public:
        Elemento();
        Elemento(std::string name);
        Elemento(const Elemento & e);

    private:
        string name;
};

Elemento::Elemento():
        name() {}

Elemento::Elemento(std::string nom):
        name(nom){}

Elemento::Elemento(const Elemento& e) :
        name(e.name) {}

#endif