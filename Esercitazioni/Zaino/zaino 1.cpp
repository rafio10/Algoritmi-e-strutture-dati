//Sia dato uno zaino che possa sopportare un determinato peso e siano dati N oggetti, ognuno dei quali caratterizzato da un peso e un valore. Il problema si propone
// di scegliere quali di questi oggetti mettere nello zaino per ottenere il maggiore valore senza eccedere il peso sostenibile dallo zaino stesso.

#include <iostream>
using namespace std;
#define N 20

int memo[N][N];

void initmemo(int num_ogg, int peso){
    for(int i=0; i<num_ogg+1; i++){
        for(int j=0; j<peso+1; j++){
            memo[i][j]=-1;
        }
    }
}

int zaino(int ogg[][2], int peso, int num_ogg){
    if(num_ogg < 0 || peso==0){
        return 0;
    }

    if(memo[num_ogg][peso]!= -1){
        return memo[num_ogg][peso];
    }

    if(peso>=ogg[num_ogg][0]){
        return memo[num_ogg][peso]=max(ogg[num_ogg][1]+zaino(ogg, peso-ogg[num_ogg][0], num_ogg-1), zaino(ogg, peso, num_ogg-1));
    }
    else{
        return memo[num_ogg][peso]=zaino(ogg, peso, num_ogg-1);
    }
}

int main(){
    int n;
    cin>>n;
    while(n--){
        int num_ogg; //dimensione zaino
        cin>>num_ogg;
        int peso; //peso massimo
        cin>>peso;
        int ogg[num_ogg][2];
        for(int i=0; i<num_ogg; i++){
            cin>>ogg[i][0]; //peso dell'oggetto
            cin>>ogg[i][1]; //valore dell'oggetto
        }

        initmemo(num_ogg, peso);
        cout<<zaino(ogg, peso, num_ogg-1)<<endl;
    }
}