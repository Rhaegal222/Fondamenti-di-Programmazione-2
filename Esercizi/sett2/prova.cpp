#include <iostream>
using namespace std;

void controllo(int *m, int rowsize, int colsize);

int main(){
    int rowsize, colsize;
    cin>>rowsize>>colsize;

    int mat[rowsize][colsize];

    for (int i=0; i<rowsize; i++){
        for (int j=0; j<colsize; j++){
            cin>>mat[i][j];
        }
    }
    
    controllo(mat[0], rowsize, colsize);
    return 0;
}

void controllo(int **m, int rowsize,  int colsize){
    bool check=false;
    for (int i=0; i < rowsize; i++){
        for (int j=0; j < colsize; j++){
            cout << m[i][j];
        }
    }
return;
}