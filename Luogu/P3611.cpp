/*
 *  Problem: P3611.cpp
 *  Author: Insouciant21
 *  Date: 2022/4/5
 */

#include <bits/stdc++.h>

using namespace std;

const int maxn = 101000;

int n;
long long ans = 0;

int main() {
    scanf("%d", &n);
    int g, f = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &g);
        ans += (g > f) ? g - f : 0;
        f = g;
    }
    printf("%lld\n", ans);
    return 0;
}