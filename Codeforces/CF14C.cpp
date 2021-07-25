/*
  Problem: CF14C
  Time: 2020/10/16 18:20:58
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

struct Point {
    int p, h;
};

struct Line {
    Point f[2];
} s[4];

int ax, ay;
bool use[4];

int main() {
    for (int i = 0; i < 4; i++) {
        scanf("%d %d %d %d", &s[i].f[0].x, &s[i].f[0].y, &s[i].f[1].x, &s[i].f[1].y);
        if (s[i].f[0].x == s[i].f[1].x)
            ax++;
        if (s[i].f[0].y == s[i].f[1].y)
            ay++;
        if (s[i].f[0].y == s[i].f[1].y && s[i].f[0].x == s[i].f[1].x) {
            puts("NO");
            return 0;
        }
    }
    if (ax == ay && ax == 2) {
        Point now = s[0].f[1];
        Point ftr = s[0].f[0];
        int sum = 0;
        int place = 0;
        int p = 0;
        use[0] = 1;
        while (sum != 3) {
            int cnt = 0;
            bool add = false;
            for (int i = 0; i < 4; i++) {
                if (use[i] || i == place)
                    continue;
                for (int j = 0; j < 2; j++) {
                    if (now.x == s[i].f[j].x && now.y == s[i].f[j].y) {
                        add = true;
                        cnt++;
                        ftr = s[i].f[!j];
                        p = i;
                    }
                }
            }
            if (cnt != 1) {
                puts("NO");
                return 0;
            }
            if (add && cnt == 1) {
                use[p] = 1;
                place = p;
                now = ftr;
                sum++;
            }
        }
        if (now.x == s[0].f[0].x && now.y == s[0].f[0].y) {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}