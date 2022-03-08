#include <iostream>
using namespace std;

const int N = 3;
const int K = 2;

void leggiMatriceA(int A[][N]);
void leggiMatriceQ(int Q[][K]);
bool verificaEsisteSimile(int A[][N], int Q[][K]);
bool verificaSimili(int A[][N], int Q[][K], int i, int j);

int main(){
    int A[N][N];
    int Q[K][K];

    leggiMatriceA(A);
    leggiMatriceQ(Q);

    if(verificaEsisteSimile(A, Q))
        cout << "Esiste una sottomatrice simile";
    else
        cout << "Non esiste";

    return 0;
}

void leggiMatrice(int A[][N]){
    for (int i = 0; i < N; i++)
        for(int j = 0;  j < N; j++)
            cin >> A [i][j];
}

void leggiMatrice(int Q[][K]){
    for (int i = 0; i < K; i++)
        for(int j = 0;  j < K; j++)
            cin >> Q[i][j];
}

bool verificaEsisteSimile(int A[][N], int Q[][K]){

    bool esisteSimile = false;
    int i = 0, j = 0;
   
    for(i = 0; i <= N-K && !esisteSimile; i++)
        for(j = 0; j <= N-K && !esisteSimile; j++){
            esisteSimile = verificaSimili(A, Q, i, j);
        }
    
    //Decremento i e j di uno in quanto vengono incrementati anche dopo aver trovato la sottomatrice
    
    i--;
    j--;
    
    if(esisteSimile){
        for(int s = 0; s < K; s++)
            for(int t = 0; t < K; t++)
                A[i+s][j+t] = Q[s][t];

         for(int s = 0; s < K; s++)
            for(int t = 0; t < K; t++)
                A[i+s][j+t] = Q[s][t];

        return true;
    }
    else{
        return false;
    }
}

bool verificaSimili(int A[][N], int Q[][K], int i, int j){

    int sommaDiagonaleA = 0, sommaDiagonaleQ = 0;
    
    for(int t = 0; t < K; t++)
    {
        sommaDiagonaleQ += Q[t][t];
        sommaDiagonaleA += A[i+t][j+t];
    }

    if(sommaDiagonaleQ == sommaDiagonaleA)
        return true;
    else
        return false;
}