/*
  Problem: CF260A
  Time: 2020/10/02 10:32:32
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

int a, b, n;

int main() {
    scanf("%d %d %d", &a, &b, &n);
    for (int i = 0; i <= 9; i++) {
        int p = a * 10 + i;
        if (p % b == 0) {
            string t = to_string(p);
            for (int i = 1; i < n; i++) t += '0';
            printf("%s\n", t.c_str());
            return 0;
        }
    }
    puts("-1");
    return 0;
}