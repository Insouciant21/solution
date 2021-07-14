/*
  Problem: UVA455
  Time: 2021/7/11 17:39
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char s[88];
        scanf("%s", s);
        int k = 1;
        bool flag = false;
        for (; k < strlen(s); k++) {
            bool find = true;
            if (strlen(s) % k != 0)
                continue;
            for (int j = k; j < strlen(s); j++) {
                if (s[j] != s[j % k]) {
                    find = false;
                    break;
                }
            }
            if (find) {
                flag = true;
                break;
            }
        }
        printf((i == n - 1) ? "%d\n" : "%d\n\n", (flag) ? k : strlen(s));
    }
    return 0;
}
