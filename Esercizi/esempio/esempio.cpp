#include <iostream>
#include <cmath>
using namespace std;

struct punto
{
    int x;
    int y;
};



int main()
{
    punto p1, p2;
    double distanza;

    cin >> p1.x >> p1.y;
    cin >> p2.x >> p2.y;

    distanza = sqrt(p1.x*p2.x);

    cout << "La distanzae': " << distanza;

    return 0;

};

 