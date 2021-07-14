/*
  Problem: UVA1585
  Time: 2021/7/11 15:38
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        char s[88];
        scanf("%s", s);
        int score = 0;
        int tot = 0;
        for (int cur = 0; cur < strlen(s); cur++) {
            if (s[cur] == 'O') {
                tot++;
                score += tot;
            }
            else
                tot = 0;
        }
        printf("%d\n", score);
    }
    return 0;
}
