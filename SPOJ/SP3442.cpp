/*
  Problem: SP3442
  Time: 2020/11/07 20:50:51
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

long long quickPow(long long a, long long b, long long p = 10) {
    long long res = 1;
    while (b) {
        if (b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long a, b;
        cin >> a >> b;
        cout << quickPow(a, b) << endl;
    }
    return 0;
}