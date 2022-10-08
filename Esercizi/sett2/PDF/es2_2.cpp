/* Esercizio 2
Leggere da tastiera una matrice M di interi di dimensione n × n e determinare se M ha un punto di sella. 
Un elemento M[i][j] è un punto di sella per M se esso è il minimo della riga i e il massimo della colonna j. */

#include<iostream>
using namespace::std;

const int N = 4;

void readMat(int M[][N], int dim){
    for (int i = 0; i < dim; i++){
        for(int j = 0; j < dim; j++){
            cin >> M[i][j];
        }
    }
}

void printMat(int M[][N], int dim){
    for (int i = 0; i < dim; i++){
        for(int j = 0; j < dim; j++){
            cout << M[i][j] << " ";
        }
    cout << endl;
    }
    cout << endl;
}

bool puntoDiSella(int M[][N],int r, int c, int N){ //come trovare un "Punto di Sella"
    int max;
    max = M[r][c];
    for (int i = 0; i < N; i++){
        if (M[i][c] > max) return false;
    }
    return true;
}

bool esistePuntoDiSella(int M[][N], int dim){ //cerco un "Punto di Sella"
    bool trovato = false;
    int min, r = 0, c = 0;
    min = M[0][0];
    for (int i = 0; i < N && !trovato; i++){
        for (int j = 0; j < N && !trovato; j++){
            if(M[i][j] < min){ //se puntoDiSella = True
                min = M[i][j];
                r = i;
                c = j;
            }
        }
        trovato = puntoDiSella(M, r, c, N);
    }
    return trovato;
}

int main(){
    int M[N][N];
    bool esiste = false;

    readMat(M,N);
    printMat(M,N);

    if(esistePuntoDiSella(M,N)) //se esistePuntoDiSella = True
        cout << "Esiste";
    else
        cout << "Non Esiste";
return 0;
}