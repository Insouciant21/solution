/*
  Problem: CF485A
  Time: 2020/10/11 10:15:36
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    long long a, m;
    cin >> a >> m;
    for (int i = 1; i <= m + 10; i++) {
        long long p = a % m;
        a += p;
        if (p == 0) {
            puts("Yes");
            return 0;
        }
    }
    puts("No");
    return 0;
}