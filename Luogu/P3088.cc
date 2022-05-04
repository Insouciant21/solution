#include <bits/stdc++.h>

using namespace std;

const int maxn = 50010;

struct Cow {
    int h;
    int x;
    bool l, r;
} h[maxn];

int n, d;
int q[maxn * 10];

int main() {

#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    cin >> n >> d;
    memset(h, 0, sizeof h);
    memset(q, 0, sizeof q);
    for (int i = 1; i <= n; i++) cin >> h[i].x >> h[i].h;
    sort(h + 1, h + 1 + n, [](Cow a, Cow b) { return a.x < b.x; });
    // for (int i = 1; i <= n; i++) { printf("%d: %d %d   ", i, h[i].x, h[i].h); }
    // puts("");
    int head = 0, tail = 0;
    for (int i = 1; i <= n; i++) {
        while (tail >= head && h[q[tail]].h < h[i].h) tail--;
        q[++tail] = i;
        while (abs(h[q[head]].x - h[i].x) > d) head++;
        if (h[i].h * 2 <= h[q[head]].h) {
            h[i].l = true;
            // printf("%d %d\n", q[head], i);
        }
    }
    /*
    for (int i = 1; i <= n; i++) {
        if (h[i].crowded) printf("i: %d\n", i);
    }
    puts("");
    */
    memset(q, 0, sizeof q);
    head = tail = 0;
    for (int i = n; i >= 1; i--) {
        while (tail >= head && h[q[tail]].h < h[i].h) tail--;
        q[++tail] = i;
        while (abs(h[q[head]].x - h[i].x) > d) head++;
        if (h[i].h * 2 <= h[q[head]].h) h[i].r = true;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += (h[i].l && h[i].r);
        // if (h[i].l && h[i].r) printf("i: %d\n", i);
    }
    cout << ans << endl;
}
