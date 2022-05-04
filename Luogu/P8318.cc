#include <bits/stdc++.h>

using namespace std;

struct Operation {
    int mode;
    int x, y;
    Operation(int a = 0, int b = 0, int c = 0) { mode = a, x = b, y = c; }
};

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    unsigned long long b[1010];
    memset(b, 0, sizeof b);
    for (int i = 1; i <= n; i++) cin >> b[i];
    Operation s[210];
    memset(s, 0, sizeof s);
    for (int i = 1; i <= m; i++) cin >> s[i].mode >> s[i].x >> s[i].y;
    for (int i = m; i > 0; i--) {
        if (s[i].mode == 1) {
            if (s[i].x != s[i].y)
                b[s[i].x] -= b[s[i].y];
            else
                b[s[i].x] /= 2;
        }
        if (s[i].mode == 2) {
            if (s[i].x != s[i].y)
                b[s[i].x] /= b[s[i].y];
            else
                b[s[i].x] = sqrt(b[s[i].x]);
        }
    }
    for (int i = 1; i <= n; i++) cout << b[i] << " ";
    cout << endl;
}
