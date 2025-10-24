#include <iostream>

using namespace std;

#define N 3

string strings[3];

int memo[N][N];

void initmemo(int n1, int n2){
    for(int i=0; i<n1+1; i++){
        for(int j=0; j<n2+1; j++){
            memo[i][j]!=-1;
        }
    }
}


int LCS(int i, int j, int k){
    if(i==strings[0].length()-1 || j==strings[1].length()-1 || k==strings[2].length()-1){
        return 0;
    }

    if(memo[i][j]!=-1){
        return memo[i][j];
    }

    int result = 0;

    if(strings[0][i] == strings[1][j] && strings[1][j] == strings[2][k]){
        result = 1 + LCS(i+1, j+1, k+1);
    }
    else{
        int option1 = LCS(i+1, j, k);
        int option2 = LCS(i, j+1, k);
        int option3 = LCS(i, j, k+1);
        result = max(option1, max(option2, option3));
    }

    memo[i][j] = result;
    return result;
}

int main(){
    int nTest;
    cout << "Inserisci il numero di casi di test: ";
    cin >> nTest;
    if(nTest<=0 || nTest >=271){
        return 0;
    }

    while(nTest--){
        for(int i=0; i<3; i++){
            cin >> strings[i];
            if(strings[i].length()<1 || strings[i].length()>60){
                break;
            }
        }

        initmemo(strings[0].length(), strings[1].length());

    }
}