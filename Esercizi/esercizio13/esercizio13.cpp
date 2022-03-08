/*Letta una sequenza di numeri terminata da -1 e lunga al più 100 elementi memorizzarla e compattare l'array, 
eliminando tutti i numeri duplicati e i relativi buchi che si generano dall'eliminazione spostando gli elementi a sinistra.*/

#include <iostream>
using namespace std;

int main(){
    int v[100], dim;
    leggi_array(v, dim);
    compatta(v, dim);
    stampa_array(v, dim);
    return 0;
}

void leggi_array(v, dim){

}

void compatta(int v[], int& dim)
{
    int i = 0;
    while (i < dim){
        if (trovato(v[i], v, 0, i-1))
            cancella(v, i , dim);
        else i++;
    }

}

bool trovato(int x, int v[], int inf, int sup){
    for (int i = inf; i <= sup; i++)
        if (v[i] == x) return true;
    return false;
}

void cancella(int v[], int pos, int& dim){
    for (int i = pos; i < dim-1; i++)
        v[i] = v[i++];
    dim--;
}

void stampa_array(v, dim){
    
}
