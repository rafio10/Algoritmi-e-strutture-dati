/*

Count the number of times a pattern appears in a given string as a subsequence
Given a string, count the number of times a given pattern appears in it as a subsequence.

Please note that the problem specifically targets subsequences that need not be contiguous, i.e., subsequences are not required to occupy consecutive positions within the original sequences.

 For example,

Input: string = “subsequence”
pattern = “sue” 
Output: 7 

With the dynamic programming approach, we can solve this problem in O(mn) time, where m and n are the lengths of the pattern and the string respectively.
*/

#include <iostream>
#include <string>

using namespace std;

int memo[1000][1000];

void initmemo(int n, int m){
    for(int i = 0; i < n+1; ++i){
        for(int j = 0; j < m+1; ++j){
            memo[i][j] = -1;
        }
    }
}

int DP(string s, string p, int n, int m){
    if(memo[n][m] != -1){
        return memo[n][m];
    }

    if(m == p.length()){
        return 1;
    }

    if(n == s.length()){
        return 0;
    }

    if(s[n] == p[m]){
        memo[n][m] = DP(s, p, n+1, m+1) + DP(s, p, n+1, m);
        return memo[n][m];
    }
    else{
        memo[n][m] = DP(s, p, n+1, m);
        return memo[n][m];
    }

}

int main(){
    int nTest;
    cin >> nTest;

    while(nTest--){
        string s, p;

        cin >> s >> p;

        int n = s.length();
        int m = p.length();

        initmemo(n, m);

        int max=0;

        cout << DP(s, p, 0, 0) << endl;
    }
}