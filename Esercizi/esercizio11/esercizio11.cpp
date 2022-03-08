/*
Ricevuto un array di char determinare se rappresenza una parola palindroma
*/

#include <iostream>
using namespace std;

bool verifica(char v[], int dim); 
main(){

}

bool verifica(char v[], int dim){
    bool palindroma = true;
    for (int i=0; i < dim/2 && palindroma; i++)
        if (v[i] != v[dim-i]) palindroma = false;
 return palindroma;
}

