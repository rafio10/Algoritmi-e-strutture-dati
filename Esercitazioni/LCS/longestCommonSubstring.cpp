//Longest Common Substring Problem

#include <iostream>
#include <string>

using namespace std;

#define N 100
int memo[N][N];

int DP(string word1, string word2, int lenght1, int lenght2){
    if (lenght1==0 || lenght2==0)
        return 0;

    if(memo[lenght1][lenght2] != -1)
        return memo[lenght1][lenght2];

    if(word1[lenght1-1] == word2[lenght2-1]){
        return memo[lenght1][lenght2] = 1 + DP(word1, word2, lenght1-1, lenght2-1);
    }

    return memo[lenght1][lenght2] = max(DP(word1, word2, lenght1, lenght2-1), DP(word1, word2, lenght1-1, lenght2));
}

void initMemo(int lenght1, int lenght2){
    for(int i=0; i< lenght1 + 1; i++){
        for(int j=0; j < lenght2 + 1; j++) {
            memo[i][j] = -1;
        }
    }
}

int main() {
    int testcase;
    string word1, word2;

    cin >> testcase;

    while(testcase--){
        cin >> word1;
        cin >> word2;
        initMemo(word1.length(), word2.length());
        int lcs = DP(word1, word2, word1.length(), word2.length());
        cout << "The longest common substring is: " << word1.substr(word1.length()-lcs, lcs) << endl;
    }
}
