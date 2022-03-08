/* data una matrice scrivere una funzione che verifica se ci sono due righe esattamente indentiche */
#include <iostream>
using namespace std;

bool verifica(const int m[][colsize], int rowsize, int colsize);

int main(){
    
}

bool verifica(const int m[][colsize], int rowsize, int colsize){
    bool trovate = false;
    for (int r1 = 0; r1 < rowsize-1; r1++)
        for (int r2 = r1 + 1; r2 < rowsize; r2++)
        {
            bool identiche = true;
            for (int c = 0; c < colsize; c++)
                if (m[r1, c] != m[r2, c]) identiche = false;
        if (identiche) trovate = true;
        }
    return trovate;
}