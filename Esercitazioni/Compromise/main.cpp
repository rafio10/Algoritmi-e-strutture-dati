#include <iostream>
#include <vector>

using namespace std;

#define N 105

int memo[N][N];

vector<string> parole;

void initmemo(int dim1, int dim2){
    for(int i=0; i<dim1+1; i++){
        for(int j=0; j<dim2+1; j++){
            memo[i][j] = -1;
        }
    }
}

int lcs(string testo1[], string testo2[], int i, int j){
    if(i == 0 || j == 0){
        return 0;
    }

    if(memo[i][j] != -1){
        return memo[i][j];
    }

    if(testo1[i] == testo2[j]){
        memo[i][j] = 1 + lcs(testo1, testo2, i-1, j-1);
        parole.push_back(testo1[i]);
        return memo[i][j];
    } else {
        memo[i][j] = max(lcs(testo1, testo2, i-1, j), lcs(testo1, testo2, i, j-1));
        return memo[i][j];
    }
}

int main(){
    int nTest;
    cin >> nTest;

    while(nTest--){
        string parola;
        string testo1[N], testo2[N];
        int i=0, j=0;

        do{
            cin >> parola;
            if(parola.length() > 30){
                return 0;
            }
            testo1[i] = parola;
            i++;
        } while(i<100 & parola != "#");

        do{
            cin >> parola;
            if(parola.length() > 30){
                return 0;
            }
            testo2[j] = parola;
            j++;
        } while(j<100 & parola != "#");

        initmemo(i, j);

        int LCS = lcs(testo1, testo2, i-1, j-1);

        cout << LCS << endl;

        for(int k=0; k<parole.size()-1; k++){
            cout << parole[k] << " ";
        }

    }
}