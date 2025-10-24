/*Given a string, count the number of times a given pattern appears in it as a subsequence.
 
For example,
Input:
string = “subsequence”
pattern = “sue”
*/
 
#include <iostream>
#include <string>
using namespace std;
 
#define N 1000
int memo[N][N];
 
void initmemo(int n, int m){
    for(int i=0; i<n+1; i++){
        for(int j=0; j<m+1; j++){
            memo[i][j]=-1;
        }
    }
}
 
 
int subString(string s, string p, int i, int j){
    if(i==s.length()){
        return 0;
    }
 
    if(j==p.length()){
        return 1;
    }
 
    if(memo[i][j]!=-1){
        return memo[i][j];
    }
   
    if(s.at(i)==p.at(j)){
        memo[i][j] = subString(s, p, i+1, j+1) + subString(s, p, i+1, j);
        return memo[i][j];
    }
    else{
        memo[i][j]=subString(s, p, i+1, j);
        return memo[i][j];
    } 
   
}
 
int main(){
    int n;
    cin>>n;
    while(n--){
        string s, p;
        cin>>s;
        cin>>p;
        int n=s.length();
        int m=p.length();
 
        initmemo(n, m);
        cout<<subString(s, p, 0, 0);
    }
}