/* PROBLEMA
Si supponga di avere N classi di prodotti, e dobbiamo acquistare un solo prodotto per ogni classe. 
Si supponga di disporre di un budget B, e di voler spendere la massimo quantità possibile (<= B) per 
acquistare un solo prodotto per classe. 
Si scriva un algoritmo che calcoli la massima quantità di denaro, minore o uguale ad B, che 
spendiamo per acquistare un prodotto per ogni classe. Nota: è possibile che il budget B non sia 
sufficiente ad acquistare un prodotto per ogni classe; in tal caso il programma stampi “denaro 
insufficiente”. 
INPUT
La prima riga dell’input contiene il numero N di casi di test. 
Per ogni caso di test: la prima riga contiene due interi, il budget B ed il numero di classi di prodotti 
C (1 ≤ B ≤ 200, e 1 ≤ C ≤ 20); le C righe successive contengono ciascuna un primo intero M (1 ≤ M ≤ 
20), che indica il numero di prodotti differenti per ogni classe, seguito da M interi che indicano il 
prezzo di ogni prodotto. Ad esempio la riga 3 8 6 4 indica che ci sono 3 prodotti per quella classe, e 
che costano rispettivamente 8, 6 e 4. 
OUTPUT
Per ogni test case, l'output da riportare è l'importo massimo di denaro necessario per acquistare un 
prodotto di ciascuna classe, senza superare il budget. Se non c'è soluzione, è necessario stampare 
"denaro insufficiente".
Sample Input
3
100 4 
3 8 6 4
2 5 10 
4 1 3 3 7
4 50 14 23 8 
20 3
3 4 6 8
2 5 10 
4 1 3 5 5 
5 3
3 6 4 8
2 10 6 
4 7 3 1 7
Sample Output
75
19
denaro insufficiente */

#include <iostream>
using namespace std;
 
#define N 100
int memo[N][N];
 
void initmemo(int budget, int classe){
    for(int i=0; i<budget+1; i++){
        for(int j=0; j<classe+1; j++){
            memo[i][j]=-1;
        }
    }
}
 
int zaino(int prodotti[][N], int c, int classe, int budget){
    if(budget<0 || classe==c){
        return 0;
    }
 
    if(memo[budget][classe]!=-1){
        return memo[budget][classe];
    }
 
    int maxval=-1;
 
    for(int i=1; i<=prodotti[classe][0]; i++){
        maxval= max(maxval,prodotti[classe][i]+zaino(prodotti, c, classe+1, budget-prodotti[classe][i]));
    }
 
    if(maxval<budget){
        memo[budget][classe]=maxval;
    }
 
    return maxval;
}
 
int main(){
    int test;
    cin>>test;
    while(test--){
        int budget, classe;
        cin>>budget>>classe;
        if(budget<1 || budget>200){
            return 0;
        }
        if(classe<1 || classe>20){
            return 0;
        }
 
        int prodotti[N][N];
        for(int i=0; i<classe; i++){
            cin>>prodotti[i][0];
            for(int j=1; j<=prodotti[i][0]; j++){
                cin>>prodotti[i][j];
            }
        }
 
        initmemo(budget, classe);
        int risultato=zaino(prodotti, classe, 0, budget);
        if(risultato==-1){
            cout<<"Budget non trovato"<<endl;
        }
        else{
            cout<<risultato<<endl;
        }
    }
}