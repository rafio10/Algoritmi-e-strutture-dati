#include <iostream>

using namespace std;

#define N 10

int memo[N];

void initmemo(int dim) {
    for (int i = 0; i < dim + 1; i++) {
        memo[i] = 0;
    }
}

int calcolo_monete(int monete[], int dim, int budget, int i) {
    int somma = 0;

    if (i < 0) {
        return 0;
    }

    if (memo[i] != 0) {
        return memo[i];
    }

    for (int j = 0; j < dim; j++) {
        if (budget > 0 && j != i) {
            somma = monete[i] + calcolo_monete(monete, dim, budget - monete[i], i - 1);
            memo[i]++;
        }
    }

    return memo[i];
}

int main() {
    int n;

    cin >> n;

    while (n--) {
        int dim;
        cin >> dim;

        int monete[dim];

        for (int i = 0; i < dim; i++) {
            cin >> monete[i];
        }

        int budget;
        cin >> budget;

        initmemo(dim);

        cout << calcolo_monete(monete, dim, budget, dim - 1);
    }

    return 0;
}
