/*
  Problem: SP4141
  Time: 2020/10/23 22:04:23
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

long long euler(int n) {
    long long phi = n;
    for (int i = 2; i <= n / i; i++) {
        if (n % i == 0) {
            phi = phi / i * (i - 1);
            while (n % i == 0) n /= i;
        }
    }
    if (n > 1) phi = phi / n * (n - 1);
    return phi;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int n;
        cin >> n;
        cout << euler(n) << endl;
    }
    return 0;
}