#include <iostream>
using namespace std;

int main(){
    int arr[20], n=1, prec, tot=0, npic=0, pic, i, x = 0;
    bool cond = false;
    while (n>=0)
    {
        cout << "Riga" << x++ << endl;
        cout << "Inserisci la temperatura: ";
        cin >> n;
        arr[tot++] = n;
    };
    x = 0;
    cout << endl;
    for (i=0; i<tot; i++){
        cout << "Riga " << x++ << endl;
        cout << arr[i] << endl;     
    };
    return 0;
}
