#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

#define N 100
#define M 1000

void backtracking(string word, string rules, int k);
bool isSafe(string word, string rules, int k);

int main(){
    ifstream inFile;
    inFile.open("input.txt");

    int testcase;
    int nWords;
    string word[N];
    int nRules;
    string rules[M];

    inFile >> testcase;

    while(testcase--){
        inFile >> nWords;
        for(int i=0; i<nWords; i++){
            inFile >> word[i];
        }
        inFile >> nRules;
        for(int i=0; i<nRules; i++){
            inFile >> rules[i];
        }

        for(int i=0; i<nWords; i++){
            for(int j=0; j<nRules; j++){
                backtracking(word[i], rules[j], 0);
            }   
        }
    }
}

void backtracking(string word, string rules, int k){

    int lengthRule = rules.size();

    if(isSafe(word, rules, k)){
        for(int i=0; i<lengthRule; i++){
            if(rules[i] == '#'){
                cout << word;
            } else if(rules[i] == '0'){
                cout << k;
            }
        }
        cout << endl;
        backtracking(word, rules, k+1);
        k--;
    }
}

bool isSafe(string word, string rules, int k){
    if(word.size()>0 && word.size()<250 && rules.size()<256 && k<10){
        return true;
    } else {return false;}
}