#include <iostream>
#include <vector>
using namespace std;

bool check(vector<string>& W, vector<vector<string>>& T){
    for(int i=0; i<W.size(); i++){//scorre la stringa generata e seleziona un carattere
        vector<string> coppia; coppia.push_back(W[i]);//inserisco la prima lettera della coppia
        for(int j=0; j<W.size(); j++){//scorre la stringa generata e seleziona un carattere
            if(i!=j){
                coppia.push_back(W[j]);//inserisco la seconda lettera della coppia
                //cout << "{"; for(auto x:coppia) cout << x << ","; cout << "}";
                vector<bool> condTransizioni(T.size(), true);
                for(auto k=0;k<T.size();k++){ //scorre il vettore delle transizioni
                    vector<string> transizione = T[k];
                    vector<bool> condCoppia(2, true);
                    for(int l=0; l<coppia.size(); l++){ //scorre la coppia
                        for(auto m:transizione){ //scorre la transizione
                            if(coppia[l] == m) condCoppia[l] = false; //setto la lettera dalla coppia a true
                        }
                    }
                    int contCondCoppia = 0;
                    for(auto n:condCoppia){
                        if(!n) contCondCoppia++;
                    }
                    if(contCondCoppia==2) condTransizioni[k] = false;
                }
                for(auto o:condTransizioni){
                    if(!o) {return false;}
                }
                coppia.pop_back();
            }
        }
        coppia.pop_back();
    }
    return true;
}

bool esercizio4(vector<string>& V, vector<vector<string>>& T, int& k, vector<string> W, int start, int index){
    if(index == k){
        if(check(W, T)) return true;
        return false;
    }
    for(int i=start;i<=V.size();i++){
        W[index] = V[i];
        if(esercizio4(V, T, k, W, start+1, index+1)) return true;
        return false;
    }
    return false;
}

int main(){
    vector<string> V = {"a","b","c",/*"d","e","f","g","h"*/};
    vector<vector<string>> T = {/*{"a","b","f","c"}, {"b","h","d"}, {"b","a","c"}, {"d","h"}, {"e","f","g","h"},*/{"a","b"},{"b","c"},{"a","c"}};
    int k = 2;
    vector<string> W(2);
    if(esercizio4(V, T, k, W, 0, 0)) cout << "SI";
    else cout << "NO";
    
    return 0;
}
