#include <iostream>
using namespace std;
int main(){
    int n, prec, somma;

    cout <<"Inserisci il primo elemento della sequenza: ";
    cin >> n;

    somma = n;
    prec = n;

    cout<<"Inserisci il prossimo numero della sequenza: ";
    cin >> n;

    while ((n!=0) || (prec!=0))
    {
        if (n==0){
           cout << "La somma della sottosequenza e': " << somma << endl;
           somma = 0;
       }
        else
            somma += n;
        prec = n;
        cout << "Inserisci il numero della prossima sequenza: ";
        cin >> n;
    }
    return 0;
}
