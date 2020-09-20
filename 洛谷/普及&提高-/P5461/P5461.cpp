/*
 *	Problem: P5461
 *	Author: Insouciant21
 *	Time: 2020/8/23 11:58:44
 */

#include <bits/stdc++.h>

using namespace std;

int n;

void pardon(vector<vector<bool>> &s) {
    int n = s.size();
    if (n == 1)
        return;
    vector<vector<bool>> a(n / 2, vector<bool>(n / 2)), b(n / 2, vector<bool>(n / 2)),
        c(n / 2, vector<bool>(n / 2)), d(n / 2, vector<bool>(n / 2));
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < n / 2; j++) s[i][j] = 0;
    }
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < n / 2; j++) b[i][j] = s[i + n / 2][j];
    }
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < n / 2; j++) c[i][j] = s[i][j + n / 2];
    }
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < n / 2; j++) d[i][j] = s[i + n / 2][j + n / 2];
    }
    pardon(b);
    pardon(c);
    pardon(d);
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < n / 2; j++) s[i + n / 2][j] = b[i][j];
    }
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < n / 2; j++) s[i][j + n / 2] = c[i][j];
    }
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < n / 2; j++) s[i + n / 2][j + n / 2] = d[i][j];
    }
}

int main() {
    cin >> n;
    int a = pow(2, n);
    vector<vector<bool>> cheater(a, vector<bool>(a));
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) cheater[i][j] = 1;
    }
    pardon(cheater);
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) (j == 0) ? cout << cheater[i][j] : cout << " " << cheater[i][j];
        cout << endl;
    }
    return 0;
}
