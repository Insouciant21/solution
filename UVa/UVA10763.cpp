/*
  Problem: UVA10763
  Time: 2020/11/07 12:28:36
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
    ios::sync_with_stdio(0);
    while (true) {
        cin >> n;
        if (!n)
            break;
        vector<int> f1, f2;
        while (n--) {
            int t1, t2;
            cin >> t1 >> t2;
            f1.push_back(t1), f2.push_back(t2);
        }
        sort(f1.begin(), f1.end());
        sort(f2.begin(), f2.end());
        if (f1 == f2)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}