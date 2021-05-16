/*
  Problem: P1205
  Time: 2021/03/03 20:10:50
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<char>> matrix, result;

vector<vector<char>> rotate90(vector<vector<char>> k) {
    vector<vector<char>> p(k);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            p[j][n - i + 1] = k[i][j];
        }
    }
    return p;
}

vector<vector<char>> rev(vector<vector<char>> k) {
    vector<vector<char>> p(k);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n / 2; j++) {
            swap(p[i][j], p[i][n - j + 1]);
        }
    }
    return p;
}

bool validate(vector<vector<char>> a, vector<vector<char>> b) {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (a[i][j] != b[i][j])
                return 0;
    return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    matrix.resize(n + 1);
    result.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        matrix[i].resize(n + 1);
        for (int j = 1; j <= n; j++) {
            cin >> matrix[i][j];
        }
    } /*
     matrix = rev(matrix);
     for (int i = 1; i <= n; i++) {
         for (int j = 1; j <= n; j++) {
             cout << matrix[i][j];
         }
         cout << endl;
     }
     */
    for (int i = 1; i <= n; i++) {
        result[i].resize(n + 1);
        for (int j = 1; j <= n; j++) {
            cin >> result[i][j];
        }
    }
    vector<vector<char>> d;
    d = rotate90(matrix);
    if (validate(d, result)) {
        cout << 1 << endl;
        return 0;
    }
    d = rotate90(d);
    if (validate(d, result)) {
        cout << 2 << endl;
        return 0;
    }
    d = rotate90(d);
    if (validate(d, result)) {
        cout << 3 << endl;
        return 0;
    }
    d = rev(matrix);
    if (validate(d, result)) {
        cout << 4 << endl;
        return 0;
    }
    d = rotate90(d);
    if (validate(d, result)) {
        cout << 5 << endl;
        return 0;
    }
    d = rotate90(d);
    if (validate(d, result)) {
        cout << 5 << endl;
        return 0;
    }
    d = rotate90(d);
    if (validate(d, result)) {
        cout << 5 << endl;
        return 0;
    }
    if (validate(matrix, result)) {
        cout << 6 << endl;
        return 0;
    }
    cout << 7 << endl;
    return 0;
}