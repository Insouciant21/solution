/*
  Problem: P2158
  Time: 2020/10/22 18:28:48
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

int phi[40010];
int n;

void work() {
    phi[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!phi[i]) {
            for (int j = i; j <= n; j += i) {
                if (!phi[j])
                    phi[j] = j;
                phi[j] = phi[j] / i * (i - 1);
            }
        }
    }
}

int main() {
    long long ans = 0;
    cin >> n;
    work();
    for (int i = 2; i < n; i++) ans += phi[i];
    cout << ((ans == 0) ? 0 : 3 + ans * 2) << endl;
    return 0;
}