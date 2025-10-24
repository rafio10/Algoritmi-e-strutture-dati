// -----------------------------------------------------------------------------------------
/* Algoritmo implementato da:  Marco Dell'Isola, Raffaele Cuzzaniti */
// -----------------------------------------------------------------------------------------
#include  <iostream>
#include <vector>
using namespace std;

#define N 500000

int merge(std::vector<int>& arr, int l, int m, int r) {
    int count = 0;
    vector<int> temp(r - l + 1);
    int i = l, j = m + 1, k = 0;

    while (i <= m && j <= r) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            /* Come indicato nella traccia si considera una inversione solo nel caso in cui i < j e Ai > Aj, per cui effettuiamo il conteggio
            con m - i + 1 che rappresenta il numero di elementi rimanenti nel primo sottovettore che sono maggiori dell'elemento corrente arr[j] nel secondo sottovettore.  */
            count += m - i + 1;
        }
    }

    while (i <= m) {
        temp[k++] = arr[i++];
    }

    while (j <= r) {
        temp[k++] = arr[j++];
    }

    for (i = 0; i < k; i++) {
        arr[l + i] = temp[i];
    }

    return count;
}

int mergeSort(std::vector<int>& arr, int left, int right) {
    // Inizializzazione variabile per il conteggio delle inversioni
    int count = 0;
    if (left >= right) {
        return 0;
    } else {
        int middle =  (right + left) / 2;

        // Dato che ogni mergeSort restituisce un valore del conteggio della corrispettiva suddivisione ne si tiene traccia
        count += mergeSort(arr, left, middle);
        count += mergeSort(arr, middle + 1, right);

        // Si aggiunge alla variabile conteggio il numero di conteggi restituiti dal merge
        count += merge(arr, left, middle, right);
    }
    return count;
}


int main() {
    int n;
    vector<int> arr;
    for(int k=0; k<N; k++){
        // Lettura della lunghezza della sequenza di numeri da considerare
        cin >> n;
        // Controllo del carattere terminatore del programma
         if(n==0){
            break;
        }
        int num;
        // Lettura della sequenza di numeri da ordinare
        for(int i=0; i < n; i++){
            cin >> num;
            arr.push_back(num);
        }
        // Invocazione della funzione merge-sort in quanto applica un approccio divide et impera
        cout << mergeSort(arr, 0 , arr.size()-1) << endl;
        arr.clear();
    }
    return 0;
}