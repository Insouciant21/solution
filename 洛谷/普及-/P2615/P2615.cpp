#include <bits/stdc++.h>

using namespace std;

int n, k;

int main() {
    cin >> n;
    k = n * n;
    vector<vector<int> > sq(n, vector<int>(n));
    int row = 0, col = (n - 1) / 2;
    int index = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) sq[i][j] = 0;
    }
    sq[row][col] = index;
    for (index = 2; index <= k; index++) {
        if (row == 0 && col != n - 1) {
            row = n - 1;
            col = col + 1;
        } else if (row != 0 && col == n - 1) {
            row--;
            col = 0;
        } else if (row == 0 && col == n - 1) {
            row++;
        } else if (row != 0 && col != n - 1) {
            if (sq[row - 1][col + 1] == 0) {
                row--;
                col++;
            } else
                row++;
        }
        sq[row][col] = index;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            (j == 0) ? cout << sq[i][j] : cout << " " << sq[i][j];
        }
        cout << endl;
    }
    return 0;
}
