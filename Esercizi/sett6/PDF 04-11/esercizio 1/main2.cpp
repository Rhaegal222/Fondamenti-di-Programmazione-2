#include "DocumentoMP3.h"
#include "DocumentoPDF.h"
#include "GestoreDocumenti.cpp"
#include <iostream>

using std::cout;

int main() {
    GestoreDocumenti lista;

    Documento doc("Rinuncia agli studi", "Unical", 1024);
    DocumentoPDF pdf("Putin", "Annessione mondiale alla Russia.pdf", 4096, false);
    DocumentoMP3 mp3("Gianni Celeste", "Povero Gabbiano.mp3", 17054, 170.0);

    lista.aggiungiDocumento(&doc);
    lista.aggiungiDocumento(&pdf);
    lista.aggiungiDocumento(&mp3);

    lista.rimuoviDocumento(&pdf);
    
    lista.stampaDocumenti();

    return 0;
}
