#include <bits/stdc++.h>
using namespace std;
int main() {
    int n = 0;
    while (scanf("%d", &n)) {
        if (n == 0) break;
        int c[101];
        memset(c, 0, sizeof c);
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            c[x]++;
        }
        bool f = true;
        for (int i = 0; i <= 100; i++) {
            for (int j = 0; j < c[i]; j++) {
                printf((f ? "%d" : " %d"), i);
                f = false;
            }
        }
        printf("\n");
    }
}