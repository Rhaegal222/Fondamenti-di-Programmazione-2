#include <iostream>
using namespace std;

bool cerca(const int v[], const int dim, const int x); /*prototipo di funzione*/
const int dim = 10;
int main(){
    int v[dim], x;
    cout << "Inserisci" << dim << "elementi \n" << endl;

    for (int i=0; i < dim; i++) cin >> v[i];
    cin >> x;
    if (cerca (v, dim, x)) cout << "trovato" << endl;
    else cout << "non trovato";
return 0;
}

bool cerca(const int v[], const int dim, const int x){ /*funzione di ricerca lineare*/
    bool trovato = false;
    for (int i=0; i < dim && !trovato; i++)
        if (v[i]==x) trovato = true;
    return trovato;
}