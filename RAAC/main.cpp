#include<iostream> 

#include<list> 

using namespace std;  

int main() 

{ 
   list<int> l{1,2,3,4};
   for(auto x:l){
      cout << x;
   }
}