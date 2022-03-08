#include <iostream>
using namespace std;

int main(){
    int n = 1, prec = 0, tot = 0, npic = 0, pic = 0;
    bool cond = false;
    cout << "Inserisci la temperatura: ";
    while (n >= 0)
    {
        cin >> n;
        tot++;
        if ((cond) && (n < prec)){
            pic = prec;
            npic++;
            cond = false;
            cout << pic << " " << tot-1 << endl;
        }        
        if ((tot > 1) && (n > prec)){
            cond = true;
            prec = n;
        }
        else{
            cond = false;
            prec = n;
        }
    }
    cout << "Numero di picchi massimi rilevati: " << npic << endl;
    cout << "Numero totale dei dati: " << tot-1;
    return 0;
}
