#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int n, cnt = 0;

void write(vector<vector<int> > &a, int x_s, int y_s, int x_d, int y_d) {
    if (cnt == n * n)
        return;
    if (n % 2 != 0 && cnt == n * n - 1) {
        a[(n - 1) / 2][(n - 1) / 2] = n * n;
        return;
    }
    for (int i = x_s; i < x_d - 1; i++) {
        cnt++;
        a[x_s][i] = cnt;
    }
    for (int i = x_s; i < y_d - 1; i++) {
        cnt++;
        a[i][y_d - 1] = cnt;
    }
    for (int i = y_d - 1; i > y_s; i--) {
        cnt++;
        a[y_d - 1][i] = cnt;
    }
    for (int i = y_d - 1; i > y_s; i--) {
        cnt++;
        a[i][x_s] = cnt;
    }
    x_s++;
    y_s++;
    x_d--;
    y_d--;
    write(a, x_s, y_s, x_d, y_d);
}

int main() {
    cin >> n;
    vector<vector<int> > square(n, vector<int>(n, 0));
    write(square, 0, 0, n, n);
    cout << setfill(' ');
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(3) << square[i][j];
        }
        cout << endl;
    }
    return 0;
}
