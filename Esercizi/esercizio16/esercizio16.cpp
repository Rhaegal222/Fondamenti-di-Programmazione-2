/*
PUNTO DI SELLA
Leggere da tastiera una matrice M di interi di dimensione N x N
(con N costante definita) e determinare se la matrice M ha un punto di sella.
Un punto di sella é un elemento della matrice che é contemporanemanete il minimo sulla sua riga ed il massimo sulla sua colonna.
*/

#include <iostream>
using namespace std;

const int n = 3;

void leggiMatrice(int M[][n]); 
void stampaMatrice(int M[][n]);
bool esistePuntoDiSella(int M[][n]);

/*
    4 1 2
M = 5 2 7
    6 2 1
*/

int main(){
    int M[n][n];
    leggiMatrice(M);
    stampaMatrice(M);
    
    if(esistePuntoDiSella(M))
        cout << "Punto di sella trovato" << endl;
    else
        cout << "Non esiste alcun punto di sella" << endl;

    return 0;
}

void leggiMatrice(int M[][n]){

    for (int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> M[i][j];

}

bool esistePuntoDiSella(int M[][n]){

    bool puntoDiSellaTrovato = false;

    for(int i = 0; i < n && !puntoDiSellaTrovato; i ++)
        for(int j = 0; j < n && !puntoDiSellaTrovato; j++)
            if(puntoDiSella(M, i, j))
                puntoDiSellaTrovato = true;
        
    if(puntoDiSellaTrovato)
        return true;
    else
        return false;
}

bool puntoDiSella(int M[][n], int i, int j){

    int min, max;

    min = M[i][0];
    max = M[0][j];

    for(int s = 1; s < n; s++){
        
        if(M[i][s] < min)
            min = M[i][s];

        if(M[s][j] > max)
            max = M[s][j];
    }

    if(M[i][j] == min && M[i][j] == max)
        return true;
    else
        return false;

}