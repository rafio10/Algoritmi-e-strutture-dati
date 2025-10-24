#include <iostream>
#include <fstream>

using namespace std;

#define N 50

bool isSafe(char matrix[][N], int i, int j, int n){
    for(int k=0; k<n; k++){
        if(matrix[k][j]=='Q' || matrix[i][k]=='Q'){
                return false;
        }
    }
    for(int k=0; k<n; k++){
        for(int h=0; h<j; h++){
            if(matrix[k][h]=='Q'){
                return false;
            }
        }
    }
    return true;
}

void backtracking(char matrix[][N], int k, int n, int q){
    if(q == n){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout << "[" << matrix[i][j] << "] ";
            }
            cout << endl;
        }
        cout << endl;
    }

    for(int i=k; i<n; i++){
        for(int j=0; j<n; j++){
            if(isSafe(matrix, i, j, n)){
                matrix[i][j] = 'Q';
                backtracking(matrix, i, n, q+1);
                matrix[i][j] = ' ';
            }
        }
    }
}

int main(){
    ifstream file;
    file.open("input.txt");
    int n;
    file >> n;
    char matrix[N][N];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            matrix[i][j] = ' ';
        }
    }
    backtracking(matrix, 0, n, 0);
    file.close();
}