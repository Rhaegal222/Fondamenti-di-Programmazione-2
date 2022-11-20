#include "AlberoB.h"
#include <iostream>

using namespace::std;

/*Esercizio 1*/
void visitaAnticipata(AlberoB<int> A, int pr){
    if(A.nullo()) return;
    for(int i=0; i<pr; i++) cout << " ";

    cout<<A.radice()<<endl;
    visitaAnticipata(A.figlio(SIN), pr-1);
    visitaAnticipata(A.figlio(DES), pr+1);
}

/*Esercizio 2*/
template <typename T>
bool isHeap(const AlberoB<T>& A){
    if(A.nullo() || A.foglia()) return true;

    if(!A.figlio(DES).nullo() && A.radice() <= A.figlio(DES).radice()){
        return false;
    }
    
    if(!A.figlio(SIN).nullo() && A.radice() <= A.figlio(SIN).radice()) {
        return false;
    }

    return isHeap(A.figlio(SIN)) && isHeap(A.figlio(DES));
}

/*Esercizio 3*/
bool ogniPercorsoRadiceFoglia(const AlberoB<int>& tree, int costo,  int k){
    if(tree.nullo())return true;
    
    costo += tree.radice(); 
    if(costo > k){ 
        cout << "Costo = " << costo << endl;
        return false;
    }

    ogniPercorsoRadiceFoglia(tree.figlio(DES), costo, k);
    ogniPercorsoRadiceFoglia(tree.figlio(SIN), costo, k);
}

/*Esercizio 4*/
bool pariEDispari(const AlberoB<int>& tree, int level){
    if (tree.nullo())
		return true;

	if ((level % 2 == 0 && tree.radice() % 2 != 0) || (level % 2 != 0 && tree.radice() % 2 == 0))
		return false;

	return pariEDispari(tree.figlio(SIN), level + 1) && pariEDispari(tree.figlio(DES), level + 1);
}

int main(){
    AlberoB<int> DIECI(10);
    AlberoB<int> NOVE(9);
    AlberoB<int> OTTO(8);
    AlberoB<int> SETTE(7);
    AlberoB<int> SEI(6);
    AlberoB<int> CINQUE(5);
    AlberoB<int> QUATTRO(4);
    AlberoB<int> TRE(3);
    AlberoB<int> DUE(2);
    AlberoB<int> UNO(1);

    DIECI.insFiglio(SIN, NOVE);
    DIECI.insFiglio(DES, SETTE);
    NOVE.insFiglio(SIN, OTTO);
    NOVE.insFiglio(DES, SEI);
    OTTO.insFiglio(SIN, CINQUE);
    OTTO.insFiglio(DES, TRE);
    SETTE.insFiglio(SIN, QUATTRO);    
    QUATTRO.insFiglio(DES, DUE);

    /*
             10
           /    \
          9      7
         / \    /
        8   6  4
       / \      \
      5   3      1
    
    */

    /*esercizio 1*/
    visitaAnticipata(DIECI, 5);
        
    /*esercizio 2*/
    if(isHeap(DIECI)) cout << "VERO" << endl;
    else cout << "FALSO" << endl;

    /*esercizio 3*/
    int k = 32;
    if(ogniPercorsoRadiceFoglia(DIECI, 0, k)) cout <<  "k = " << k << "\nNessun percorso con costo maggiore di k."<< endl;
    else cout << "k = " << k << "\nTrovato percorso con costo superiore a k."<< endl;

    /*esercizio 4*/
    if(pariEDispari(DIECI, 0)) cout << "Condizioni rispettate!" << endl;
    else cout << "Condizioni NON rispettate!" << endl;

}