/*
  Problem: P1012
  Time: 2021/5/22 16:21
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

int n;
vector<string> a;

bool k(string a, string b) {
    return a + b > b + a;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string t;
        cin >> t;
        a.push_back(t);
    }
    sort(a.begin(), a.end(), k);
    string ans;
    for (string &i : a) {
        ans += i;
    }
    cout << ans << endl;
    return 0;
}
