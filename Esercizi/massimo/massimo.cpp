#include <iostream>
using namespace std;

int main()
{
    int curval, maxval = 0;
    cout << "digita una lettera per terminare" << endl;
    while (cin >> curval)
        {
            if (curval > maxval)
            {
                maxval = curval;
            }
        }
    if (maxval)
    {
        cout << "Il massimo e': " << maxval << endl;
    }     
    else
    {
        cout << "nessun dato" << endl;
    }
    return 0;
};

 