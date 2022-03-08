#include <iostream>
using namespace std;

/*
mcd(x, y) = x se y = 0
mcd(x, y) = mcd(y, r)
*/
int mcd(int x, int y) {
    int r = x % y;
    if (r == 0) return y;
    return mcd(y, r);
}

int main(){

    return 0;
}