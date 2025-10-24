#include <iostream>

using namespace std;

#define N 100

int memo[N][N];

void initmemo(int dim) {
    for (int i = 0; i < dim + 1; i++) {
        for (int j = 0; j < dim + 1; j++) {
            memo[i][j] = -1;
        }
    }
}

int LCS(string str, int i, int dim, int dimStringa) {

    if (dim < 0 || i > dimStringa) {
        return 0;
    }

    if (memo[i][dim] != -1) {
        return memo[i][dim];
    }

    if (str[i] == str[dim]) {
        memo[i][dim] = 1 + LCS(str, i + 1, dim - 1, dimStringa);
    } else {
        memo[i][dim] = max(LCS(str, i + 1, dim, dimStringa), LCS(str, i, dim - 1, dimStringa));
    }

    return memo[i][dim];
}

int main() {
    int nTest;
    cin >> nTest;

    while (nTest--) {

        string inputString;
        cin >> inputString;

        int dim = inputString.length();

        if (dim > 1000) {
            cout << "Stringa troppo lunga" << endl;
            return 0;
        }

        initmemo(dim);

        cout << LCS(inputString, 0, dim - 1, dim - 1) << endl;
    }

    return 0;
}
