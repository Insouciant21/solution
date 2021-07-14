/*
  Problem: UVA133
  Time: 2021/7/12 14:00
  Author: Insouciant21
  Status: AC
*/

#include <bits/stdc++.h>

using namespace std;

int c[21];
int n;
int k, m;

int go(int position, int direction, int step) {
    while (step--) {
        do {
            position = (position + direction + n - 1) % n + 1;
        } while (c[position] == -1);
    }
    return position;
}

int main() {
    while (scanf("%d %d %d", &n, &k, &m) == 3 && n) {
        for (int i = 1; i <= n; i++)
            c[i] = i;
        int left = n;
        int a = n, b = 1;
        while (left) {
            a = go(a, 1, k);
            b = go(b, -1, m);
            if (left != n)
                printf(",");
            left--;
            printf("%3d", c[a]);
            if (a != b) {
                left--;
                printf("%3d", c[b]);
            }
            c[a] = c[b] = -1;
        }
        printf("\n");
    }
    return 0;
}
