/*

Sample Input
2
4
4 3 2 1
1 2 3 4
3 1 2 4
4 3 2 1
6
1 2 3 4 5 6
1 2 3 4 6 5
6 3 5 1 2 4
5 4 6 2 1 3
2 4 1 3 5 6
1 2 6 5 4 3
Sample Output
TEST OUTPUT
1
2
4
TEST OUTPUT
5
3
2
4
3

*/

// La complessità è: O(n^2) dato che si scorre la matrice una volta sola e si memorizzano i risultati in una matrice di appoggio. 
// Dato che lo facciamo per n-1 righe ottengo una complessità: O(n^3)

// Ho ritenuto non necessario inserire lo zero alla fine di ogni caso di test dato che la terminazione è implicita con la dimensione inserita.
// Inoltre la stampa viene effettuata alla fine di ogni caso di test

#include <iostream>
 
using namespace std;

#define N 15

int memo[N][N];
 
void initmemo(int dim){
    for(int i=0; i<dim+1; i++){
        for(int j=0; j<dim+1; j++){
            memo[i][j]=-1;
        }
    }
}
 
int DP(int matrix[][N], int dim1, int dim2, int k){
    if(dim1<0 || dim2<0){
        return 0;
    }
 
    if(memo[dim1][dim2]!=-1){
        return memo[dim1][dim2];
    }
 
    if(matrix[0][dim1]==matrix[k][dim2]){
        return memo[dim1][dim2]=1+DP(matrix, dim1-1, dim2-1, k);
    }
    else{
        return memo[dim1][dim2]=max(DP(matrix, dim1-1, dim2, k), DP(matrix, dim1, dim2-1, k));
    }
}
 
int main(){
    int nTest;
    cin >> nTest;

    while(nTest--){
        int dim;
        cin >> dim;
        if(dim<2 || dim>10){
            cout << "Dimensione non corretta!";
            return 0;
        }
 
        int matrix[N][N];
        for(int i=0; i<dim; i++){
            for(int j=0; j<dim; j++){
                cin>>matrix[i][j];
            }
        }

        cout << "TEST OUTPUT" << endl;
        for(int k=1; k<dim; k++){
            initmemo(dim);
            cout << DP(matrix, dim-1, dim-1, k) << endl;
        }    
    }
}