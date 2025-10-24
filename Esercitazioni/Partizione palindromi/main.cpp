#include <iostream>

using namespace std;

#define N 100

int memo[N][N];

void initmemo(int dim){
    for(int i=0;i<dim+1;i++){
        for(int j=0;j<dim+1;j++){
            memo[i][j]=-1;
        }
    }
}

int DP(string s, int i, int j, int dimStringa){
    if(j<0 || i>dimStringa){
        return 0;
    }

    if(memo[i][j]!=-1){
        return memo[i][j];
    }

    if(i==j){
        memo[i][j]=1;
        return memo[i][j];
    }

    if(s[i]==s[j]){
        memo[i][j]=DP(s, i+1, j-1, dimStringa);
    }
    else{
        memo[i][j]=1+max(DP(s, i+1, j, dimStringa), DP(s, i, j-1, dimStringa));
    }

    return memo[i][j];
}

int main(){
    int nTest;
    cin >> nTest;

    while(nTest--){

        string s;
        cin >> s;

        int dim=s.size();

        if(dim<1 || dim>1000){
            cout << "errore" << endl;
            return 0;
        }

        initmemo(dim);

        cout << DP(s, 0, dim-1, dim-1) << endl;

    }
}

