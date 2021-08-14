/*
  Problem: CF399B
  Time: 2020/10/02 14:37:23
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

int n;
string init;
bitset<50> in, out;

long long ans;

int main() {
    scanf("%d", &n);
    init.resize(n);
    scanf("%s", &init[0]);
    for (int i = 0; i < n; i++) in[i] = (init[i] == 'R') ? 1 : 0, out[i] = 1;
    ans = out.to_ullong() - in.to_ullong();
    printf("%I64d\n", ans);
    return 0;
}