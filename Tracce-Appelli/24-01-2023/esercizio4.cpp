#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check(vector<vector<int>>& S, vector<int>& H){
    vector<bool> condS(S.size(), false);
    for(int i=0; i<S.size(); i++){
        for(auto x:S[i]){
            for(auto y:H){
                if(y==x) condS[i] = true;
            }
        }
    }
    for(auto x:condS) if(!x) return false;
    return true;
}

bool esercizio4Unofficial(vector<vector<int>>& S, vector<int>& H, int& k, int& n, int index){
    // if(H.size() == k && check(S,H)) return true; else return false; //SBAGLIATO COME LA MIA VITA
    if(H.size() == k){ 
        if(check(S, H)) return true; 
        return false; 
    }
    
    for(int i=0; i<n; i++){
        H.push_back(i);
        if(esercizio4Unofficial(S, H, k, n, i+1)) return true;
        H.pop_back();
    }
    return false;
}

//VERSIONE DA FARE PER L'ESAME

void next(int& x, int& n){
   x++;// se l'indice è inferiore al numero massimo di elementi incrementa l'indice
}

void add(int x, vector<int>& sol){
    sol.push_back(x); //aggiunge il prossimo elemento alla soluzione
}

void remove(vector<int>& sol){
    sol.pop_back(); //rimuove l'ultimo elemento dalla soluzione
}

bool isComplete(vector<int>& sol, vector<vector<int>>& listaInsiemi, int& k){
    if(sol.size() < k) return false;
    for(auto x:sol) cout<<x<< " "; cout<<endl;
    vector<bool> check(listaInsiemi.size(), false); //inizializza un vettore tutto false per verificare ogni singola stringa nella lista
    for(int i=0; i<listaInsiemi.size(); i++){ //scorre la lista contenente le stringhe
        for(auto x:listaInsiemi[i]){ //scorre la stringa selezionata
            for(auto y:sol){ //scorre la soluzione
                if(y==x) check[i] = true; //se nella stringa selezionata c'è un elemento della soluzione setta a true la stringa
            }
        }
    }
    for(auto x:check) if(!x) return false; //se è trova una stringa rimasta false la condizione non è verificata 
    return true; //la condizione è verificata
}

bool canAdd(int index, vector <int> sol){
    if(find(sol.begin(), sol.end(), index) == sol.end()) return true; // se nella soluzione non è presente un elemento uguale lo aggiunge
    return false;
}

bool esercizio4(vector<vector<int>>& S, vector<int>& H, int& k, int& n){
    int index = 0;
    while(index < n){
        if(canAdd(index, H)){
            add(index, H);
            if(isComplete(H, S, k)) return true;
            else if(esercizio4(S,H,k,n)) return true;
            remove(H); next(index, n);
        }
        else next(index, n);
    }
    return false;
}

int main(){
    vector<vector<int>> S{{1, 2, 3}, {4, 3, 5}, {5, 6}};
    vector<int> H;
    int k = 3, n = 5;
    if(esercizio4Unofficial(S,H,k,n,0)) cout << "SI"; else cout << "NO"; cout << endl;
    if(esercizio4(S,H,k,n)) cout << "SI"; else cout << "NO";
    
    return 0;
}
