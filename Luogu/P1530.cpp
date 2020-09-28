/*
  Problem: P1530
  Time: 2020/09/26 13:24:03
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

int n, d;

void work() {
    vector<int> dec, rem;
    int p = 0x3f3f3f;
    while (true) {
        dec.push_back(n / d);
        int x = n % d;
        if (x == 0)
            break;
        p = distance(rem.begin(), find(rem.begin(), rem.end(), x));
        if (p != rem.size())
            break;
        p = 0x3f3f3f;
        rem.push_back(x);
        n = x * 10;
    }
    int cnt = 0;
    if (dec.size() == 1)
        cout << dec[0] << ".0" << endl;
    else {
        cout << dec[0] << ".";
        string x = to_string(dec[0]);
        cnt = x.length() + 1;
        for (unsigned i = 1; i < dec.size(); i++) {
            if (cnt % 76 == 0)
                cout << endl;
            if (p + 1 == i) {
                cout << "(";
                cnt++;
            }
            cout << dec[i];
            cnt++;
        }
        if (p != 0x3f3f3f)
            cout << ")";
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> d;
    work();
    return 0;
}