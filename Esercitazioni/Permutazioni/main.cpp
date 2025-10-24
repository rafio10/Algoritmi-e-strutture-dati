#include <iostream>

using namespace std;

#define N 200

int memo[N][N];

void initmemo(int dim){
    for(int i=0; i<dim+1; i++){
        for(int j=0; j<dim+1; j++){
            memo[i][j] = -1;
        }
    }
}
int solve(int arr1[], int arr2[], int n, int n1, int n2){
    if(n1 >= n || n2 >= n){
        return 0;
    }

    if(memo[n1][n2]!=-1){
        return memo[n1][n2];
    }

    if(arr1[n1] == arr2[n2]){
        memo[n1][n2] = solve(arr1, arr2, n, n1+1, n2+1);
    } else {
        memo[n1][n2] = 2 + min(solve(arr1, arr2, n, n1+1, n2), solve(arr1, arr2, n, n1, n2+1));
    }

    return memo[n1][n2];
}

int main(){
    int nTest;
    cin >> nTest;
    if(nTest > 40){
        return 0;
    }

    while(nTest--){
        int dim;
        cin >> dim;
        if(dim > 200){
            return 0;
        }

        int arr1[N], arr2[N];

        for(int i=0; i<dim; i++){
            cin >> arr1[i];
        }

        for(int i=0; i<dim; i++){
            cin >> arr2[i];
        }

        initmemo(dim);

        cout << "Caso " << nTest << ": " << solve(arr1, arr2, dim-1, 0, 0) << endl;
    }
}