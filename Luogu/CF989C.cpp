/*
  Problem: CF989C
  Time: 2020/10/01 14:00:24
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

int a, b, c, d;
char mp[55][55];

void work(char type) {
    if (type == 'a' && a) {
        for (int i = 19; i <= 36; i += 2) {
            for (int j = 1; j <= 50; j += 2) {
                mp[i][j] = 'A';
                a--;
                if (!a)
                    return;
            }
        }
    }
    if (type == 'b' && b) {
        for (int i = 28; i <= 36; i += 2) {
            for (int j = 1; j <= 50; j += 2) {
                mp[i][j] = 'B';
                b--;
                if (!b)
                    return;
            }
        }
    }
    if (type == 'c' && c) {
        for (int i = 1; i <= 36; i += 2) {
            for (int j = 1; j <= 50; j += 2) {
                mp[i][j] = 'C';
                c--;
                if (!c)
                    return;
            }
        }
    }
    if (type == 'd' && d) {
        for (int i = 10; i <= 36; i += 2) {
            for (int j = 1; j <= 50; j += 2) {
                mp[i][j] = 'D';
                d--;
                if (!d)
                    return;
            }
        }
    }
}

int main() {
    scanf("%d%d%d%d", &a, &b, &c, &d);
    puts("36 50");
    for (int i = 1; i <= 36; i++) {
        for (int j = 1; j <= 50; j++) {
            switch ((i - 1) / 9) {
                case 0:
                    mp[i][j] = 'A';
                    break;
                case 1:
                    mp[i][j] = 'B';
                    break;
                case 2:
                    mp[i][j] = 'C';
                    break;
                case 3:
                    mp[i][j] = 'D';
                    break;
                default:
                    break;
            }
        }
    }
    a--, b--, c--, d--;
    for (char i = 'a'; i <= 'd'; i++) work(i);
    for (int i = 1; i <= 36; i++) {
        for (int j = 1; j <= 50; j++) printf("%c", mp[i][j]);
        printf("\n");
    }
    return 0;
}