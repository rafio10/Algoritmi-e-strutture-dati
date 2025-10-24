#include <iostream>
#include <fstream>

using namespace std;

#define N 50

// Funzione che verifica se è "sicuro" posizionare una regina in una determinata posizione
bool isSafe(char q[][N], int n, int r, int c){
	for(int i=0; i<n; i++){ // Controllo la riga e la colonna
		if(q[r][i]=='Q' || q[i][c]=='Q'){
			return false;
		}
	}
	
    for (int i = r, j = c; i >= 0 && j >= 0; i--, j--) { // Controllo la diagonale superiore sinistra
        if (q[i][j] == 'Q') {
            return false;
        }
    }
    
    for (int i = r, j = c; i < n && j >= 0; i++, j--) { // Controllo la diagonale inferiore sinistra
        if (q[i][j] == 'Q') {
            return false;
        }
    }

    for (int i = r, j = c; i >= 0 && j < n; i--, j++) { // Controllo la diagonale superiore destra
        if (q[i][j] == 'Q') {
            return false;
        }
    }

    for (int i = r, j = c; i < n && j < n; i++, j++) { // Controllo la diagonale inferiore destra
        if (q[i][j] == 'Q') {
            return false;
        }
    }
	
	return true;
}

// Funzione ricorsiva per la risoluzione del problema
void backtracking(char matrix[][N], int k, int n, int q, int& count){
    // Se q==n, allora abbiamo posizionato tutte le regine quindi incremento il contatore che tiene traccia di tutte le possibili soluzioni
    if(q == n){
        count++;
    }

    for(int i=k; i<n; i++){
        for(int j=0; j<n; j++){
            // Se è sicuro posizionare una regina, la posiziono e richiamo la funzione ricorsivamente
            if(isSafe(matrix, n, i, j)){
                matrix[i][j] = 'Q';
                backtracking(matrix, i, n, q+1, count);
                // Ripristino delle celle come spazi vuoti
                matrix[i][j] = ' '; 
            }
        }
    }
}

int main(){
    // Apertura del file in input e lettura dei testcase
    ifstream file;
    file.open("input.txt");
    int testcase;
    file >> testcase;
    char matrix[N][N];
    // Per ogni testcase leggi i dati dal file ed inizializza le celle come spazi vuoti
    while(testcase--){
        int count = 0;
        int n;
        file >> n;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                matrix[i][j] = ' ';
            }
        }
        backtracking(matrix, 0, n, 0, count);
        cout << count << endl;
    }
    file.close();
}