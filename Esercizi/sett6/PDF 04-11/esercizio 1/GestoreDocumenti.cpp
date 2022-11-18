#include "GestoreDocumenti.h"
#include <iostream>
#include <algorithm>

using namespace std;

bool GestoreDocumenti::esisteDocumento(Documento* documento){
    for (list<Documento *>::iterator it = listaDocumenti.begin(); it != listaDocumenti.end(); it++){
        Documento selected = **it;
        if(selected.getProprietario() == documento->getProprietario() && selected.getDimensioneFile()==documento->getDimensioneFile() && selected.getDescrizione() == documento->getDescrizione())
            return true;}
    return false;
}

void GestoreDocumenti::aggiungiDocumento(Documento* documento){
    if(!esisteDocumento(documento)){
        listaDocumenti.push_back(documento);
        cout << documento->getProprietario() << " " << documento->getDescrizione() << " " << documento->getDimensioneFile() << ": Aggiunto" << endl;
    }
    else
        cout << documento->getProprietario() << " " << documento->getDescrizione() << " " << documento->getDimensioneFile() << ": Non Aggiunto" << endl;

}

void GestoreDocumenti::rimuoviDocumento(Documento* documento){
    if(esisteDocumento(documento)){
        for (list<Documento *>::iterator it = listaDocumenti.begin(); it != listaDocumenti.end(); it++){
        Documento selected = **it;
        if(selected.getProprietario() == documento->getProprietario() && selected.getDimensioneFile()==documento->getDimensioneFile() && selected.getDescrizione() == documento->getDescrizione()){

            listaDocumenti.remove(documento);
            
            cout << documento->getProprietario() << " " << documento->getDescrizione() << " " << documento->getDimensioneFile() << ": Rimosso" << endl;
            break;
            }
        }
    }
    else
        cout << documento->getProprietario() << " " << documento->getDescrizione() << " " << documento->getDimensioneFile() << ": Non Rimosso" << endl;
}

void GestoreDocumenti::stampaDocumenti() const {
    int cont = 0;
    cout << endl;
    for (list<Documento *>::const_iterator it = listaDocumenti.begin(); it != listaDocumenti.end(); it++){
        cout << cont++ << " ";
        Documento selected = **it;
        cout << selected.getProprietario() << " " << selected.getDescrizione() << " " << selected.getDimensioneFile() << endl;}
}

void GestoreDocumenti::ordinaDocumenti(int valore){
    switch (valore)
    {
    case 1:
        /* code */
        break;
    
    case 2:
        /* code */
        break;

    case 3:
        /* code */
        break;
    }
}