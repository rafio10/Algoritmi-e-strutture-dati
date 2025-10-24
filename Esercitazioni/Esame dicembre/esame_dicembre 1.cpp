#include <iostream>
#define N 10
using namespace std;

void init_memo(int memo[][N+1]){
	for (int i=0; i<N+1; i++){
		for (int j=0; j<N+1; j++){
			memo[i][j]=0;
		}
	}
}

void print_memo(int memo[][N+1]){
	for(int i=0;i<N+1;i++){
			for(int j=0; j<N+1; j++){
				cout<<memo[i][j]<<"  ";
			}
			cout<<endl;
		}
	cout<<endl<<endl;
}

int combinazione(int budget, int prodotti, int prezzo[][N], int memo[][N+1], int classe) {
    // Caso base: se abbiamo esaurito tutte le classi, restituisci 0
    if (classe == prodotti) {
        return 0;
    }

    // Se il risultato è già stato calcolato, restituiscilo senza ricalcolare
    if (memo[classe][budget] != 0) {
        return memo[classe][budget];
    }

    int maxSpent = 0;

    // Prova ad acquistare ogni prodotto nella classe corrente
    for (int i = 1; i <= prezzo[classe][0]; i++) {
            // Calcola la spesa massima scegliendo il prodotto corrente
            int spent = prezzo[classe][i] + combinazione(budget - prezzo[classe][i], prodotti, prezzo, memo, classe + 1);
            // Aggiorna la massima spesa possibile
            maxSpent = max(maxSpent, spent);
    }

    // Memorizza il risultato per evitare ricalcoli
    memo[classe][budget] = maxSpent;

    // Restituisci la massima spesa possibile per questa classe e budget
    if(memo[classe][budget]>=budget){
    	return -1;
	}
    return memo[classe][budget];
}
	
	
int main(){
	int n; //numero casi di test
	cin>>n;
	while(n--){
		int budget,prodotti;
		int prezzo[N][N];
		cin>>budget;
		cin>>prodotti;
		for(int i=0;i<prodotti;i++){
			cin>>prezzo[i][0];
			for(int j=1; j<=prezzo[i][0]; j++){
				cin>>prezzo[i][j];
			}
		}
		
		int memo[N+1][N+1];
		init_memo(memo);
		
		int risultato=combinazione(budget,prodotti,prezzo,memo, 0);
		if(risultato==-1){
			cout<<"Denaro insufficiente!"<<endl;
		}else{
			cout<<"Risultato: "<<risultato<<endl;
		}
		//print_memo(memo);
	}
}
