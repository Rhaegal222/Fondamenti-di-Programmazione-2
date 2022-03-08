#include <iostream>
using namespace std;

bool ePrimo(int n){
    bool primo=true;
    for (int k=n/2; k>1 && primo; k--){
        if (n%k==0) return false;
    }
    return primo;
}

int main(){
    int numero, somma = 0, ins = 0;
    while (numero != -50)
    {
        cin >> numero;
        if (numero != -50){
            ins++;
            somma += numero;
        }     
    }
    cout << somma << endl;
}