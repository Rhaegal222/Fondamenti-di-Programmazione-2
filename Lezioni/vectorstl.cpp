#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
int i;
int main(){
    vector<int> vectorint(6,0);
    for (int i=0; i < vectorint.size(); i++)
        cout << vectorint[i];
        vectorint[i]=i; // vectorint.pushback(i);

for (vector<int>::iterator i = vectorint.begin(); i != vectorint.end(); i++)
    cout << *i << "/t";

copy(vectorint.begin(), vectorint.end(), ostream_iterator<int>(cout, "  "));
}