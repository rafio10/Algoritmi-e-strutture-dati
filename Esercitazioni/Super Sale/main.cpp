/*There is a SuperSale in a SuperHiperMarket. Every person can take only one object of each kind, i.e.
one TV, one carrot, but for extra low price. We are going with a whole family to that SuperHiperMarket.
Every person can take as many objects, as he/she can carry out from the SuperSale. We have given
list of objects with prices and their weight. We also know, what is the maximum weight that every
person can stand. What is the maximal value of objects we can buy at SuperSale?
Input
The input consists of T test cases. The number of them (1 ≤ T ≤ 1000) is given on the first line of
the input file. Each test case begins with a line containing a single integer number N that indicates
the number of objects (1 ≤ N ≤ 1000). Then follows N lines, each containing two integers: P and W.
The first integer (1 ≤ P ≤ 100) corresponds to the price of object. The second integer (1 ≤ W ≤ 30)
corresponds to the weight of object. Next line contains one integer (1 ≤ G ≤ 100) its the number of
people in our group. Next G lines contains maximal weight (1 ≤ MW ≤ 30) that can stand this i-th
person from our family (1 ≤ i ≤ G).
Output
For every test case your program has to determine one integer. Print out the maximal value of goods
which we can buy with that family.
Sample Input
2
3
72 17
44 23
31 24
1
26
6
64 26
85 22
52 4
99 18
39 13
54 9
4
23
20
20
26
Sample Output
72
514*/

#include <iostream>
#include <algorithm>

using namespace std;

#define N 1000

int memo[N][N];

void initmemo(int nObject, int nPeople){
    for(int i=0; i<nObject+1; i++){
        for(int j=0; j<nPeople; j++){
            memo[i][j]=-1;
        }
    }
}

int DP(int object[][2], int nObject, int nPeople, int maxWeight[], int weight[]){
    if(nObject<0 || nPeople<0){
        return 0;
    }
    
    if(memo[nObject][nPeople]!=-1){
        return memo[nObject][nPeople];
    }

    for(int i=0; i<nObject; i++){
        if(weight[nPeople-1]<maxWeight[nPeople-1]){
            weight[nPeople-1]+=maxWeight[nPeople-1]-object[i][0];
            memo[nObject][nPeople]=max(object[i][1] + DP(object, nObject-1, nPeople-1, maxWeight, weight), DP(object, nObject-1, nPeople, maxWeight, weight));
        }
        else {
            memo[nObject][nPeople] = DP(object, nObject-1, nPeople, maxWeight, weight);
        }
    }

    return memo[nObject][nPeople];
}

int main(){

    int nTest;
    cout << "Inserisci il numero di casi di test: ";
    cin >> nTest;

    if(nTest <= 0 || nTest > 1000){
        return 0;
    }

    int nObject;
    int object[1000][2];
    int nPeople;
    int maxWeight[N];

    while(nTest--){

        cout << "Inserisci il numero di oggetti: ";
        cin >> nObject;
        if(nObject <= 0 || nObject > 1000){
            return 0;
        }
        
        cout << "Inserisci gli oggetti: ";
        for(int i=0; i<nObject; i++){
            cin >> object[i][0] >> object[i][1];
            if(object[i][0] > 100 || object[i][1] > 30){
                return 0;
            }
        }

        cout << "Inserisci il numero di persone: ";
        cin >> nPeople;
        if(nPeople < 0 || nPeople > 100){
            return 0;
        }

        cout << "Inserisci il peso massimo per ogni persona: ";
        for(int i=0; i<nPeople; i++){
            cin >> maxWeight[i];
            if(maxWeight[i] < 0 || maxWeight[i] > 30){
            return 0;
        }
        }
        
        initmemo(nObject, nPeople);

        int weight[nPeople];
        for(int i=0; i<nPeople; i++){
            weight[i]=0;
        }

        cout << DP(object, nObject, nPeople, maxWeight, weight);
    }
}

