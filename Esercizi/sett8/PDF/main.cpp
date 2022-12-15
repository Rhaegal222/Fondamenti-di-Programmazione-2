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

    return ogniPercorsoRadiceFoglia(tree.figlio(DES), costo, k) && ogniPercorsoRadiceFoglia(tree.figlio(SIN), costo, k);
}

/*Esercizio 4*/
bool pariEDispari(const AlberoB<int>& tree, int level){
    if (tree.nullo())
		return true;

	if ((level % 2 == 0 && tree.radice() % 2 != 0) || (level % 2 != 0 && tree.radice() % 2 == 0)){
		return false;
    }

	return pariEDispari(tree.figlio(SIN), level + 1) && pariEDispari(tree.figlio(DES), level + 1);
}

/*Esercizio 5*/
    bool vocaliEConsonanti(const AlberoB<char>& tree, int vow, int cons){
    
    if(tree.nullo())return true;

    if(tree.radice() == 'a' || tree.radice() == 'e' || tree.radice() == 'i' || tree.radice() == 'o' || tree.radice() == 'u')
        vow += 1;
    else
        cons += 1;

    if (vow > cons+1 || cons > vow+1)
        return false; 

    return vocaliEConsonanti(tree.figlio(SIN), vow, cons) && vocaliEConsonanti(tree.figlio(DES), vow, cons);
}

int main(){
    AlberoB<int> UNDICI(11);
    AlberoB<int> DIECI(10);
    AlberoB<int> NOVE(9);
    AlberoB<int> NOVEC(9);
    AlberoB<int> OTTO(8);
    AlberoB<int> SETTE(7);
    AlberoB<int> SEI(6);
    AlberoB<int> CINQUE(5);
    AlberoB<int> CINQUEC(5);
    AlberoB<int> QUATTRO(4);
    AlberoB<int> TRE(3);
    AlberoB<int> DUE(2);
    AlberoB<int> UNO(1);

    AlberoB<char> A('a');
    AlberoB<char> B('b');
    AlberoB<char> C('c');
    AlberoB<char> D('d');
    AlberoB<char> E('e');
    AlberoB<char> F('f');
    AlberoB<char> G('g');
    AlberoB<char> H('h');
    AlberoB<char> I('i');
    AlberoB<char> J('j');
    AlberoB<char> O('o');

    //UNO.insFiglio(SIN, SETTE);          /*  1.F 2.kmax=25 3.F 4.F */
    //UNO.insFiglio(DES, NOVE);           /*           1            */
    //NOVE.insFiglio(DES, NOVEC);         /*         /    \         */
    //NOVEC.insFiglio(SIN, CINQUEC);      /*        7      9        */
    //SETTE.insFiglio(SIN, DUE);          /*       / \      \       */
    //SETTE.insFiglio(DES, SEI);          /*      2   6      9      */
    //SEI.insFiglio(SIN, CINQUE);         /*         / \    /       */
    //SEI.insFiglio(DES, UNDICI);         /*        5   11 5        */

    DIECI.insFiglio(SIN, NOVE);         /*  1.T 2.kmax=32 3.T 4.T */      
    DIECI.insFiglio(DES, SETTE);        /*            10          */
    NOVE.insFiglio(SIN, OTTO);          /*          /    \        */
    NOVE.insFiglio(DES, SEI);           /*         9      7       */
    OTTO.insFiglio(SIN, CINQUE);        /*        / \    /        */
    OTTO.insFiglio(DES, TRE);           /*       8   6  4         */
    SETTE.insFiglio(SIN, QUATTRO);      /*      / \      \        */
    QUATTRO.insFiglio(DES, UNO);        /*     5   3      1       */

    //A.insFiglio(SIN, B);                /*         A      */
    //A.insFiglio(DES, C);                /*       /   \    */
    //B.insFiglio(SIN, E);                /*      B     C   */
    //B.insFiglio(DES, D);                /*     / \    /   */
    //C.insFiglio(SIN, F);                /*    E   D  F    */
    //F.insFiglio(DES, I);                /*   / \      \   */
    //E.insFiglio(SIN, G);                /*  G   H      I  */
    //E.insFiglio(DES, H);                /*             /  */
    //I.insFiglio(DES, O);                /* TRUE       O   */

    A.insFiglio(SIN, B);                /*         A        */
    A.insFiglio(DES, C);                /*       /   \      */
    B.insFiglio(SIN, E);                /*      B     C     */
    B.insFiglio(DES, D);                /*     / \    /     */
    D.insFiglio(DES, J);                /*    E   D  F      */
    C.insFiglio(SIN, F);                /*   / \   \  \     */
    F.insFiglio(DES, I);                /*  G   H   J  I    */
    E.insFiglio(SIN, G);                /*             /    */
    E.insFiglio(DES, H);                /*            O     */
    I.insFiglio(DES, O);                /*       FALSE      */

    /*esercizio 1*/
    visitaAnticipata(DIECI, 5);
        
    /*esercizio 2*/
    if(isHeap(DIECI)) cout << "Nessun elemento con valore informativo maggiore di quello di tutti i propri figli." << endl;
    else cout << "Trovato elemento con valore informativo maggiore di quello di tutti i propri figli." << endl;

    /*esercizio 3*/
    int k = 32;
    if(ogniPercorsoRadiceFoglia(DIECI, 0, k)) cout << "Nessun percorso con costo maggiore di k. " << "(k = " << k << ")" << endl;
    else cout << "Trovato percorso con costo superiore a k." << "(k =" << k << ")" << endl;

    /*esercizio 4*/
    cout << "Pari e dispari: ";
    if(pariEDispari(DIECI, 0)) cout << "Condizioni rispettate!" << endl;
    else cout << "Condizioni NON rispettate!" << endl;

    /*esercizio 5*/
    cout << "Vocali e consonanti : ";
    if(vocaliEConsonanti(A, 0, 0)) cout << "Condizioni rispettate!" << endl;
    else cout << "Condizioni NON rispettate!" << endl;


}