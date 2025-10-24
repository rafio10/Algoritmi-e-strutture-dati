/*
    COMPLESSITA': DP(i) con 0<=i<nMoney* ==> #sottoproblemi O(nMoney); tempo/sottoproblema = O(1)
    COMPLESSITA' TEMPORALE = O(nMoney)
*/

#include <iostream>
#include <climits>
using namespace std;

int* memo;

void initMemo(int dim);
int MaxValue(int arr[],int sum1,int sum2,int i, int nMoney);

int main(){

    int nTest=0;  //numero casi di test
    int nMoney=0;  //numero monete
    int* arr; // array di memorizazzione monete

    cin>>nTest;

    while(nTest--){

        cin>>nMoney;

        arr = new int[nMoney];
        for(int i=0; i<nMoney; i++){
            cin>>arr[i]; //inserimento monete nell'array
        }

        //calcolo della somma totale delle monete, utilizzata per l'instanziazione dell'array memo
        int sum;
        for(int i=0; i < nMoney; i++){
            sum += arr[i];
        }

        initMemo(sum); //funzione che inizializza l'array memo[] il quale verrà utilizzato per memorizzare i risultati intermedi dei sottoproblemi già risolti

        cout << MaxValue(arr,0,0,nMoney-1, nMoney) << endl; //funzione ricorsiva di dynamic programming

        delete [] memo;
    }
    return 0;

}

int MaxValue(int arr[],int sum_1,int sum_2,int i, int nMoney){
    // se l'indice i è minore di zero, significa che si è esaurito l'array delle monete e la differenza tra le due somme parziali sum_1 e sum_2 rappresenta la differenza tra i due gruppi di monete
    if (i < 0)
        return abs(sum_1 - sum_2);
        
    // questo indice viene utilizzato per accedere all'array di memoizzazione memo.
    int index = i + sum_1;    

    // se il valore in memo[index] è diverso da -1, significa che è stato già calcolato in precedenza e memorizzato, quindi viene restituito direttamente quel valore memorizzato
    if (memo[index] != -1)
        return memo[index];
        
    // aggiungo l'elemento corrente arr[i] al primo gruppo (sum_1)
    int diff1 = MaxValue(arr, sum_1+ arr[i], sum_2, i - 1, nMoney);  
    // aggiungo l'elemento corrente arr[i] al secondo gruppo (sum_2).
    int diff2 = MaxValue(arr, sum_1, sum_2 + arr[i], i - 1, nMoney); 
    // memorizzo il risultato minimo tra queste due possibilità nell'array memo e restituisco tale valore
    memo[index] = min(diff1, diff2);    
    return memo[index];
}

void initMemo(int dim){

    memo = new int[dim];
    for(int i=0; i<dim; i++){
        memo[i] = -1;
    }

}