/*
  Problem: CF762A
  Time: 2020/09/30 19:50:31
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<ll> divisor;

ll n, k;

void work() {
    ll t = sqrt(n);
    for (ll i = 1; i <= t; i++) {
        if (n % i == 0) {
            divisor.push_back(i);
            if (i != n / i)
                divisor.push_back(n / i);
        }
    }
}

int main() {
    scanf("%lld%lld", &n, &k);
    work();
    sort(divisor.begin(), divisor.end());
    if (k > divisor.size()) {
        puts("-1");
        return 0;
    }
    printf("%lld\n", divisor[k - 1]);
    return 0;
}