#ifndef UTENTE_H
#define UTENTE_H

#include <iostream>
#include <string>
using std::cout;
using std::ostream;
using std::string;

class Utente {

private:
    int numero;
    int tipologiaOperazione; //0: spedizione, 1: pagamento, 2: riscossione

public:
    Utente() {}
    Utente(int numero, int tipologiaOperazione) :
        numero(numero),
        tipologiaOperazione(tipologiaOperazione) {}

    Utente(const& Utente);

    int getNumero() const { return numero; }
    int getTipologiaOperazione() const { return tipologiaOperazione; }
};

ostream& operator<<(ostream& o, const Utente& c) {
    o << "Numero" << c.getNumero() << "Tipologia Operazione: " << c.getTipologiaOperazione();
    return o;
}

#endif
