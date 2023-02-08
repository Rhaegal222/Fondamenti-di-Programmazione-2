#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isComplete(vector<int>& sol, vector<vector<int>>& listaInsiemi, int& k){
    if(sol.size() < k) return false;
    //for(auto x:sol) cout<<x<< " "; cout<<endl;
    for(auto x:listaInsiemi){ //scorre il vettore delle stringhe
        bool cond = false;
        for(auto y:sol) if(find(x.begin(), x.end(), y)!=x.end()) cond = true; //scorre la combinazione e controlla che il carattere selezionato è presente nella stringa
        if(!cond) return false; //se non è presente almeno un carattere della combinazione nella sottostringa restituisce falso
    }
    return true; //la condizione è verificata
}

bool canAdd(int index, vector <int> sol){
    if(find(sol.begin(), sol.end(), index) == sol.end()) return true; // se nella soluzione non è presente un elemento uguale lo aggiunge
    return false;
}

bool esercizio4(vector<vector<int>>& S, vector<int>& H, int& k, int& n){
    int index = 0;
    if(!(H.empty())) index = H.back();
    while(index < n){
        if(canAdd(index, H)){
            H.push_back(index);
            if(isComplete(H, S, k))return true;
            if(esercizio4(S,H,k,n)) return true;
            H.pop_back();
        }
        index++;
    }
    return false;
}

int main(){
    vector<vector<int>> S{{1, 2, 3}, {4, 3, 5}, {5, 6}};
    vector<int> H;
    int k = 3, n = 5;
    if(esercizio4(S,H,k,n)) cout << "SI"; else cout << "NO"; cout << endl;
    
    return 0;
}