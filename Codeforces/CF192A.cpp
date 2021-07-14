/*
  Problem: CF192A
  Time: 2020/10/01 12:31:52
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

long long num;

int main() {
    scanf("%lld", &num);
    long long n = 8 * num + 2;
    int sqt = sqrt(n);
    for (long long i = 3; i <= sqt; i += 2) {
        long long p = n - i * i;
        double c = sqrt(p);
        if (p > 1 && c == int(c) && int(c) % 2 == 1) {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}