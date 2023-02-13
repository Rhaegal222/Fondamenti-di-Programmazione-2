#include<iostream> 

#include<list> 

using namespace std;  

int main() 
{ 
   int a = 0;
   cout << a+1 << endl; // stampa il a incerementato senza cambiarne il valore
   cout << a++ << endl; // stampa il valore e poi incrementa a
   cout << ++a << endl; // incrementa a e poi lo stampa
}