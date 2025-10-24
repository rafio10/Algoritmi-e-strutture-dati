#include <iostream>
#include <fstream>

using namespace std;

#define N 50

void mergesort(int array[], int l, int r);
void merge(int array[], int l, int m, int r);

int main(){
    ifstream inFile;
    inFile.open("input.txt");

    int testcase;
    int dim;

    int array[N];

    inFile >> testcase;

    while(testcase--){
        inFile >> dim;
        for(int i=0; i<dim; i++){
            inFile >> array[i];
        }

        mergesort(array, 0, dim-1);

        cout << array[0] << " " << array[dim-1] << endl;
    }

    inFile.close();

}

void mergesort(int array[], int l, int r){ 
    if(l<r){
        int m = l + (r-l)/2;
        mergesort(array, l, m);
        mergesort(array, m+1, r);
        merge(array, l, m, r);
    }
}

void merge(int array[], int l, int m, int r){
    int n1 = m-l+1;
    int n2 = r-m;

    int L[n1];
    int M[n2];

    for(int i=0; i<n1; i++){
        L[i] = array[l+i];
    }

    for(int j=0; j<n2; j++){
        M[j] = array[m+1+j];
    }

    int i=0;
    int j=0;
    int k=l;

    while(i<n1 && j<n2){
        if(L[i]<=M[j]){
            array[k]=L[i];
            i++;
        } else {
            array[k]=M[j];
            j++;
        } 
        k++;
    }

    while(i<n1){
        array[k] = L[i];
        i++;
        k++;
    }

    while(j<n2){
        array[k] = M[j];
        j++;
        k++;
    }
}