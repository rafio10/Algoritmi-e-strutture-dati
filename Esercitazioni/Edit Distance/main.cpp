#include <iostream>

using namespace std;

#define N 100

int memo[N][N];

int minOp(int a, int b, int c){
    return min(a, min(b, c));
}

void initmemo(int dim1, int dim2){
    for(int i=0; i<dim1; i++){
        for(int j=0; j<dim2; j++){
            memo[i][j]=-1;
        }
    }
}

int DP(string s1, string s2, int i, int j){
    if(i<0 || j<0){
        return 0;
    }

    if(i==0){ // se arrivo alla fine di una stringa, devo cancellare tutti i caratteri rimanenti dell'altra
        return j;
    }

    if(j==0){ // se arrivo alla fine di una stringa, devo cancellare tutti i caratteri rimanenti dell'altra
        return i;
    }

    if(memo[i][j]!=-1){
        return memo[i][j];
    }

    if(s1[i]==s2[j]){
        memo[i][j]=DP(s1, s2, i-1, j-1);
    }
    else {
        memo[i][j]=1+minOp(DP(s1, s2, i-1, j), DP(s1, s2, i, j-1), DP(s1, s2, i-1, j-1));
    }

    return memo[i][j];
}

int main(){
    int nTest;
    cin >> nTest;

    while(nTest--){
        string s1, s2;
        cin >> s1 >> s2;

        int dim1=s1.size(), dim2=s2.size();

        initmemo(dim1, dim2);

        cout << DP(s1, s2, dim1-1, dim2-1) << endl;

    }
}