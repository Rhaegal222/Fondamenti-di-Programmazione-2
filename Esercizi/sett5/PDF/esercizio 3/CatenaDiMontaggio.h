#ifndef CATENADIMONTAGGIO_H
#define CATENADIMONTAGGIO_H

#include "ListaT.h"
#include "Elemento.h"

using namespace std;

template <class T>
class CatenaDiMontaggio{
    public:

        void aggiungi(T elemento); //aggiunge un elemento alla fine della lista
        
		void rimuovi(); //rimuove il primo elemento della lista
        
		const T& prossimo(); //restituisce il primo elemento della lista
       
	    unsigned int size() const;//restituisce il numero di elementi della lista
    
	private:
		List<T>::~List(elemento)
};

#endif