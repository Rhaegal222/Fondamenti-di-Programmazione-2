/* 
ARRAY MULTIMENSIONALI
int m[3][4];
int arr[10][20][30];
int m[3][4] = {{0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}};
m[i][j] || m[i,j]

DICHIARAZIONE E STAMPA DI UN ARRAY MULTIMENSIONALE

const int rowsize=...
const int colsize=...

void print(const int m[][colsize], int rowsize, int colsize)
{
    for (int i =0; i < rowsize, i++)
        {
            for (int j = 0; j < colsize; j++)
                cout << m[i][j] << "\t"
            cout << endl;
        }
}
*/