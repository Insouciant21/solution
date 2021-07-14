/*
  Problem: CF900B
  Time: 2020/09/30 20:02:46
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

int a, b, c;

void work(int num, int div, int f) {
    vector<int> dec, rem;
    int p = 0x3f3f3f;
    int cnt = 0;
    int type = 0;
    while (true) {
        dec.push_back(num / div);
        int x = num % div;
        if (x == 0) {
            type = 1;
            break;
        }
        p = distance(rem.begin(), find(rem.begin(), rem.end(), x));
        if (p != rem.size()) {
            type = 2;
            break;
        }
        p = 0x3f3f3f;
        rem.push_back(x);
        num = x * 10;
    }
    if (type == 1)
        dec.push_back(0);
    for (unsigned int i = 1; i < dec.size(); i++) {
        if (dec[i] == f) {
            cout << i << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> a >> b >> c;
    work(a, b, c);
    return 0;
}