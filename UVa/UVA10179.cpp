/*
  Problem: UVA10179
  Time: 2020/10/23 22:18:09
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

int euler(int n) {
    int phi = n;
    int s = sqrt(n) + 0.5;
    for (int i = 2; i <= s; i++) {
        if (n % i == 0) {
            phi = phi / i * (i - 1);
            while (n % i == 0)
                n /= i;
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