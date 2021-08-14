/*
  Problem: CF866A
  Time: 2020/09/29 20:56:52
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> a;
int sum;

int main() {
    a.resize(6);
    for (int i = 0; i < 6; i++) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum % 2 != 0) {
        cout << "NO" << endl;
        return 0;
    }
    sort(a.begin(), a.end());
    bool ok = false;
    do {
        int k = accumulate(a.begin(), a.begin() + 3, 0);
        ok = (sum / 2 == k);
    } while (next_permutation(a.begin(), a.end()) && !ok);
    if (ok) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}