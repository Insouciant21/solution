/*
  Problem: UVA11426
  Time: 2020/10/23 21:27:49
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

long long euler(int n) {
    if (n < 2)
        return 0;
    long long phi = n;
    for (int i = 2; i <= n; i++) {
        if (n % i == 0) {
            phi = phi / i * (i - 1);
            while (n % i == 0) n /= i;
        }
    }
    if (n > 1)
        phi = phi / n * (n - 1);
    return phi;
}

int main() {
    int n;
    while (true) {
        cin >> n;
        if (n == 0)
            break;
        cout << euler(n) << endl;
    }
    return 0;
}