#include <iostream>
#include <vector>

using namespace std;

int maxSubArraySum(const vector<int>& arr) {
    int n = arr.size();
    
    // Creazione di un vettore per memorizzare la somma massima fino a ogni indice
    vector<int> dp(n, 0);
    
    // Il massimo sottointervallo inizia con il primo elemento
    dp[0] = arr[0];
    
    // Calcolo della somma massima fino a ogni indice
    for (int i = 1; i < n; ++i) {
        dp[i] = max(arr[i], dp[i - 1] + arr[i]);
    }
    
    // Trovare il massimo valore nel vettore dp
    int maxSum = dp[0];
    for (int i = 1; i < n; ++i) {
        maxSum = max(maxSum, dp[i]);
    }
    
    return maxSum;
}

int main() {
    // Esempio di utilizzo con un array di interi
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    
    int result = maxSubArraySum(arr);
    
    cout << "La somma massima di una sottosequenza contigua è: " << result << endl;

    return 0;
}
