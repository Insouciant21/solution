/*
  Problem: P7588
  Time: 2021/7/7 16:37
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

int prime[5800000];
bitset<int(1e8 + 1)> num;
int dpc = 0;

void make_prime() {
    int cnt = 0;
    for (int i = 2; i < 100000001; i++) {
        if (!num[i]) prime[cnt++] = i;
        for (int j = 0; j < cnt && i * prime[j] < 100000001; j++) {
            num[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    for (int i = 0; i < cnt; i++) {
        int sum = 0;
        int p = prime[i];
        while (p) {
            sum += p % 10;
            p /= 10;
        }
        if (!num[sum]) prime[dpc++] = prime[i];
    }
}

int main() {
    make_prime();
    int t;
    scanf("%d", &t);
    while (t--) {
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%d\n", upper_bound(prime, prime + dpc, r) - lower_bound(prime, prime + dpc, l));
    }
    return 0;
}