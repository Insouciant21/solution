/*
  Problem: CF121A
  Time: 2020/10/08 07:52:53
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

long long num[10000];

long long sum(int n) {
    if (n == 0)
        return 0;
    long long res = 0;
    for (int i = 1;; i++) {
        if (num[i] < n)
            res += num[i] * (num[i] - num[i - 1]);
        else {
            res += num[i] * (n - num[i - 1]);
            break;
        }
    }
    return res;
}

int main() {
    int l, r;
    cin >> l >> r;
    num[1] = 4, num[2] = 7;
    for (int i = 1, tot = 2; num[i] * 10 + 4 <= (long long)(1e10); i++) {
        num[++tot] = num[i] * 10 + 4;
        num[++tot] = num[i] * 10 + 7;
    }
    cout << sum(r) - sum(l - 1) << endl;
    return 0;
}