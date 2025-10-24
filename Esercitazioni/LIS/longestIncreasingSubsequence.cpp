#include <iostream>
using namespace std;


int longestIncreasingSubsequence(int vettore[],int n){
    int longest=0;
    for(int i=0; i<n-1; i++){
        int j=i+1; //mi serve per scorrere nel vettore
        int l=1; //lunghezza della sottosequenza
        int value = vettore[i];
        while(j<n && vettore[j]>value){
            value = vettore[j];
            l++;
            j++;
        }
        if(l>longest){
            longest=l;
        }
    }

    return longest;
}



int main(){

    int vettore[] = {7,2,3,4,7,10,3,4,0,1};
    int n = sizeof(vettore)/sizeof(int);

    cout<<longestIncreasingSubsequence(vettore,n);


    return 0;
}
