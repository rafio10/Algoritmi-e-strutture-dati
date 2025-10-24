#include <iostream>

using namespace std;

int somma(int arr[], int dim){
    int i=0;
    int somma1;
    int somma2;
    int sommaFin;
    while(i<dim){
        for(int j=0; j<=i; j++){
            somma1+=arr[j];
        }
        for(int k=i+1; k<dim; k++){
            somma2+=arr[k];
        }

        if(somma1==somma2){
            sommaFin=somma1;
        }
        i++;
        somma1=0;
        somma2=0;
    }
    return sommaFin;
}

int main(){
    cout << "Inserisci il numero di casi di test: ";
    int nTest;
    cin >> nTest;

    while(nTest--){

        cout << "Inserisci la dimensione dell'array: ";
        int dim;
        cin >> dim;

        cout << "Inserisci gli elementi nell'array: ";

        int arr[dim];

        for(int i=0; i<dim; i++){
            cin >> arr[i];
        }

        cout << somma(arr, dim);
    }









}