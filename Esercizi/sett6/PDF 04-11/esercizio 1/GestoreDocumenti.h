#ifndef GESTOREDOCUMENTI_H
#define GESTOREDOCUMENTI_H

#include <list>
#include "Documento.h"

class GestoreDocumenti{
    private:
        list<Documento*> listaDocumenti;
    public:
        GestoreDocumenti(){};
        bool esisteDocumento(Documento*);
        void aggiungiDocumento(Documento*);
        void rimuoviDocumento(Documento*);
        void stampaDocumenti() const;
        void ordinaDocumenti(int valore);
};

#endif