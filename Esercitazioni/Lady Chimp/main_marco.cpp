#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#define N 500

void tallest(vector<int>& heightLadys, int left, int nLadys, int heightLuciu, int& shorter, int& higher){
    if(left >= nLadys) {
        return;
    }
    
    int m = left + (nLadys - left)/2;
    tallest(heightLadys, left, m, heightLuciu, shorter, higher);
    tallest(heightLadys, m + 1, nLadys, heightLuciu, shorter, higher);
    
    if (heightLadys[m]< heightLuciu){
        if(shorter == 0) {
            shorter = heightLadys[m];
        } else if(heightLadys[m]>shorter){
            shorter = heightLadys[m];
        }
    }
    if (heightLadys[m]>heightLuciu){
        if(higher == 0) {
            higher = heightLadys[m];
        } else if(heightLadys[m]<higher){
            higher = heightLadys[m];
        }
    }
}

int main(){
    ifstream File;
    int nLadys;
    int nLuciu;
    vector<int> heightLadys;
    vector<int> heightsLuciu;
    int shorter = 0;
    int higher = 0;
    int p;
    File.open("input.txt");
    File >> nLadys;
    for(int i=0; i<nLadys; i++){
        File >> p;
        heightLadys.push_back(p);
    }
    File >> nLuciu;
    for(int i=0; i<nLuciu; i++){
        File >> p;
        heightsLuciu.push_back(p);
    }
    for(int i=0; i<nLuciu; i++){
        tallest(heightLadys, 0, nLadys, heightsLuciu[i], shorter, higher);
        if( shorter == 0) {
            cout << "x" << " " << higher << endl;
        } else if(higher == 0){
            cout << shorter << " " << "x" << endl;
        } else {
            cout << shorter << " " << higher << endl;
        }
        shorter = 0 ;
        higher = 0;
    }
}