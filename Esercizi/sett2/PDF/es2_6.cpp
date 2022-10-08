/* Esercizio 6 */

#include<iostream>
using namespace::std;

const int N = 5;

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

int search(int M[][N], int dif){
    bool cond = true;
    for(int rip = 0; rip < dif; rip++)
        for(int i = 0+rip; i < N; i++){
            for(int j = 0; j < N; j++){
                if(M[i][j] != M[i][j+1]){
                    cond = false;
                }

            }
        }
}

int main(){
    int M[N][N];

    readMat(M,N);
    printMat(M, N);

    search(M, 1);
    
    return 0;
}