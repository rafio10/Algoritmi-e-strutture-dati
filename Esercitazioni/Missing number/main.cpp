#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

void mergeSort(int array[], int l, int r, int missingNumber);
void merge(int array[], int l, int m, int r, int missingNumber);

int main(){

    int n, p;
    int missingNumber;

    ifstream inFile;
    inFile.open("input.txt");

    inFile >> n;

    int array[n-1];

    for(int i=0; i<n-1; i++){
        inFile >> p;
        array[i] = p;
    }

    mergeSort(array, 0, n-1, missingNumber);

    int size = *(&array + 1) - array;

    for(int i=size-1; i>0; i--){       
        if(array[i] != array[i-1]+1){
            missingNumber = array[i-1] + 1;
        }
    }

    cout << missingNumber;

}

void mergeSort(int array[], int l, int r, int missingNumber){
    if(l == r){
        return;
    }
        int m = l + (r-l)/2;
        mergeSort(array, l, m, missingNumber);
        mergeSort(array, m+1, r, missingNumber);
        merge(array, l, m, r, missingNumber);
}


void merge(int array[], int l, int m, int r, int missingNumber){

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
        if(L[i]<M[j]){
            array[k] = L[i];
            i++;
        } else{
            array[k] = M[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
    array[k] = L[i];
    i++;
    k++;
    }

  while (j < n2) {
    array[k] = M[j];
    j++;
    k++;
    }
}