#include <iostream>
using namespace std;

const int dim = 10;

int main(){
    int a[dim];
    cout << "Inserisci" << dim << "elementi" << endl;
    for (int i = 0; i < dim; i++)
        cin >> a[0];
    cout << "L'array letto è: \n";
    for (int i = 0; i < dim; i++)
        cout << a[i] << endl;
    return 0;
}
/* 
void print (int ia[]...){

}

void print (int *a ...)

void print (const int ia[], int size{
    for (int i = 0; i < size; i++)
        cout << ia[i] << endl;
}

void print (const int (&ia)[dim]{
    Far capire che si tratta effettivamente di un array e non di un puntatore
}
*/
