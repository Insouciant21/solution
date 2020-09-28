/*
 *	Problem: P1835
 *	Author: Insouciant21
 *	Time: 2020/8/25 13:08:38
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void simpleSieve(ll limit, vector<ll> &prime) {
    bool mark[limit + 1];
    memset(mark, 0, sizeof(mark));
    for (ll i = 2; i <= limit; ++i) {
        if (mark[i] == false) {
            prime.push_back(i);
            for (ll j = i; j <= limit; j += i) mark[j] = true;
        }
    }
}

void primesInRange(ll low, ll high) {
    ll limit = floor(sqrt(high)) + 1;
    vector<ll> prime;
    simpleSieve(limit, prime);
    int n = high - low + 1;
    bool mark[n + 1];
    memset(mark, 0, sizeof(mark));
    for (ll i = 0; i < prime.size(); i++) {
        int loLim = floor(low / prime[i]) * prime[i];
        if (loLim < low)
            loLim += prime[i];
        if (loLim == prime[i])
            loLim += prime[i];
        for (ll j = loLim; j <= high; j += prime[i]) mark[j - low] = true;
    }
    ll ans = 0;
    for (ll i = low; i <= high; i++)
        if (!mark[i - low])
            ans++;
    cout << ans << endl;
}

int main() {
    ll low, high;
    scanf("%lld %lld", &low, &high);
    primesInRange(low, high);
    return 0;
}