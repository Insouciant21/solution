/*
  Problem: P1851
  Time: 2021/5/20 21:31
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

int s;

int factorSum(int k) {
    int sum = 0;
    for (int i = 1; i < k; i++)
        if (k % i == 0)
            sum += i;
    return sum;
}

int main() {
    scanf("%d", &s);
    int a = s;
    while (1) {
        int b = factorSum(a);
        int c = factorSum(b);
        if (c == a && a != b) {
            printf("%d %d\n", a, b);
            break;
        }
        a++;
    }
    return 0;
}
