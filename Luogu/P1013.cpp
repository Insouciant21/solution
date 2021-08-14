/*
 *  Problem: P1013
 *  Author: Insouciant21
 *  Time: 2020/9/14 19:16:21
 *  Status: Accepted
 */

#include <bits/stdc++.h>

using namespace std;

int n;

string add[10][10];
int p[] = {123123123, 1, 312, 3, 12, 312, 3, 1, 2321, 12};

char ls[10];

map<char, int> value;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> add[i][j];
            if (i == 1 && j != 1) ls[j - 1] = add[i][j][0];
        }
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= n; j++)
            if (add[i][j].length() < 2) value[add[i][j][0]]++;
    }
    for_each(value.begin(), value.end(), [](pair<const char, int> &m) { m.second--; });
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1 || j == 1) continue;
            int a = 0, b = 0, c = 0;
            unsigned z = add[i][j].length();
            a = value[add[i][1][0]];
            b = value[add[1][j][0]];
            for (int k = 0; k < z; k++)
                c += value[add[i][j][k]] * pow(n - 1, z - k - 1);
            if (a + b != c) {
                cout << "ERROR!" << endl;
                return 0;
            }
        }
    }
    int cnt = 1;
    while (cnt <= n - 1) {
        for (auto iter = value.begin(); iter != value.end(); iter++) {
            if (iter->first == ls[cnt]) {
                cout << iter->first << "=" << iter->second << " ";
                cnt++;
                break;
            }
        }
    }
    cout << endl;
    cout << n - 1 << endl;
    return 0;
}
