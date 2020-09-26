/*
  Problem: CF1146B
  Time: 2020/09/26 16:42:48
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    string t1;
    cin >> t1;
    string t2 = t1;
    t2.erase(remove(t2.begin(), t2.end(), 'a'), t2.end());
    if (t2.length() % 2 != 0) {
        cout << ":(" << endl;
        return 0;
    }
    string k = t2.substr(0, t2.length() / 2);
    string p = t2.substr(t2.length() / 2, t2.length());
    if (k != p) {
        cout << ":(" << endl;
        return 0;
    }
    for (int i = t1.length() - t2.length() / 2; i < t1.length(); i++)
        if (t1[i] == 'a') {
            cout << ":(" << endl;
            return 0;
        }
    for (int i = 1; i <= k.length(); i++) t1.pop_back();
    cout << t1 << endl;
    return 0;
}