#include <iostream>
using namespace std;

int main(){
    int val = 0, card_fam = 0, card_max = 0, card = 0;
    cout << "Inserisci la sequenza: ";
    while (val != -1)
    {
        cin >> val;
        while (val != 0)
        {
            card++;
        }
        card_fam = card;
        if (card_fam < card_max){
            card_max = card_fam;
        }
        card = 0;

        cout << "Cardinalita' della famiglia: " << card_fam << endl;
        cout << "Cardinalità massima" << card_max << endl;
    }
}
