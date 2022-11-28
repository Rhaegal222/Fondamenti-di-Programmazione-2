#include "Camera.h"
#include <iostream>
using namespace std;

int main(){
    Singola s;
    Doppia d;
    Tripla t;
    int costo = s.calcolaCosto()+d.calcolaCosto()+t.calcolaCosto();
    cout << "Costo totale: " << costo << endl;
    cout << s.tipologia();

    return 0;
}