/*
 *  Problem: P5535
 *  Author: Insouciant21
 *  Time: 2020/9/6 21:23:05
 *  Status: Accepted
 */

#include <bits/stdc++.h>

using namespace std;

long long n;
long long k;

bool prime(long long x) {
    if (x < 2)
        return 0;
    for (long long i = 2; i <= sqrt(x); i++)
        if (x % i == 0)
            return 0;
    return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    if (2 * k + 2 >= n + 1 && prime(k + 1))
        cout << 1 << endl;
    else
        cout << 2 << endl;
    return 0;
}
