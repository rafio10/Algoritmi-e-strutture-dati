//MinCostPath
#include <iostream>
#define N 10
using namespace std;

int memo[N][N];

void initmemo(int dim){
	for(int i=0; i<dim+1; i++){
			for(int j=0; j<dim+1; j++){
				memo[i][j]=-1;
			}
		}
}

int minimo(int a, int b, int c){
	return min(a, min(b,c));
}

int minCostPath(int m[N][N], int i, int j){
	if(i<0 || j<0){
		return INT16_MAX;
	}
	
	if(i==0 && j==0){
		return m[0][0];
	}
	
	if(memo[i][j]!=-1){
		return memo[i][j];
	}
	else{
		memo[i][j]=m[i][j]+minimo(minCostPath(m, i-1, j-1),minCostPath(m, i, j-1), minCostPath(m, i-1, j));
	}
	
	return memo[i][j];
}

int main(){
	int n;
	cin>>n;
	while(n--){
		int dim;
		cin>>dim;
		int m[N][N];
		for(int i=0; i<dim; i++){
			for(int j=0; j<dim; j++){
				cin>>m[i][j];
			}
		}	
		initmemo(dim);
		cout<<minCostPath(m, dim-1, dim-1)<<endl;
		
	}
}
