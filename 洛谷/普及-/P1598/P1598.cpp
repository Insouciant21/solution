/*
*	Problem: P1598
*	Author: Insouciant21
*	Time: 2020/8/22 20:37:45
*/

#include <bits/stdc++.h>

using namespace std;

int fre[26];
string a, b, c, d;
string s;

int main() {
    getline(cin, a);
    getline(cin, b);
    getline(cin, c);
    getline(cin, d);
    s = a + b + c + d;
    for (char i = 'A'; i <= 'Z'; i++) {
        fre[i - 65] = count(s.begin(), s.end(), i);
    }
    int n = *(max_element(begin(fre), end(fre)));
    vector<vector<string> > histo(n + 1, vector<string>(26));
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < n + 1; j++) {
            histo[j][i] = " ";
        }
    }
    for (int i = 0; i < 26; i++) 
        histo[n][i] = char(i + 65);
    for (int i = 0; i < 26; i++) {
        for (int j = n - 1; j >= n - fre[i]; j--) {
            histo[j][i] = "*";
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 26; j++) {
            (j != 0) ? cout << " " << histo[i][j] : cout << histo[i][j];
        }
        cout << endl;
    }
    return 0;
}
