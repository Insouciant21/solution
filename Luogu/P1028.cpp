/*
  Problem: P1028
  Time: 2021/5/22 16:01
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

int n;
int mem[501];

long long ans = 1;

int main() {
    cin >> n;
    for (int i = 0; i <= 501; i++)
        mem[i] = 1;
    for (int i = 1; i <= n / 2; i++) {
        for (int j = 1; j <= i / 2; j++) {
            mem[i] += mem[j];
        }
    }
    for (int i = 1; i <= n / 2; i++)
        ans += mem[i];
    cout << ans << endl;
    return 0;
}
