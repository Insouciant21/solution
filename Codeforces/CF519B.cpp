/*
  Problem: CF519B
  Time: 2021/6/19 17:35
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> org, at1, at2;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        org.push_back(t);
    }
    for (int i = 0; i < n - 1; i++) {
        int t;
        cin >> t;
        at1.push_back(t);
    }
    for (int i = 0; i < n - 2; i++) {
        int t;
        cin >> t;
        at2.push_back(t);
    }
    sort(org.begin(), org.end());
    sort(at1.begin(), at1.end());
    sort(at2.begin(), at2.end());
    bool ok = false;
    for (int i = 0; i < n - 1; i++) {
        if (org[i] != at1[i]) {
            cout << org[i] << endl;
            ok = true;
            break;
        }
    }
    if (!ok) cout << org[n - 1] << endl;
    ok = false;
    for (int i = 0; i < n - 2; i++) {
        if (at1[i] != at2[i]) {
            cout << at1[i] << endl;
            ok = true;
            break;
        }
    }
    if (!ok) cout << at1[n - 2] << endl;
    return 0;
}
