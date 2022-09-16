#include <bits/stdc++.h>

using namespace std;

int n, m1, m2;

const int maxn = 100010;

struct Air {
    int ld, tf;
    bool used = false;
    Air(int a = 0, int b = 0) { ld = a, tf = b, used = false; }
};

class cmp {
   public:
    bool operator()(const Air &x, const Air &y) { return x.ld < y.ld; }
};

int sum[2][maxn];
int d[maxn], in[maxn];

void arrange(int *df, const vector<Air> &p) {
    int t[maxn];
    memset(t, 0, sizeof t);
    for (auto i : p) {
        int j = 0;
        for (j = 0; j < n; j++)
            if (i.ld >= t[j]) break;
        df[j]++, t[j] = i.tf;
    }
}

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin >> n >> m1 >> m2;
    vector<Air> dome, inter;
    for (int i = 0; i < m1; i++) {
        int a, b;
        cin >> a >> b;
        dome.emplace_back(a, b);
    }
    for (int i = 0; i < m2; i++) {
        int a, b;
        cin >> a >> b;
        inter.emplace_back(a, b);
    }
    sort(dome.begin(), dome.end(), cmp());
    sort(inter.begin(), inter.end(), cmp());
    arrange(d, dome), arrange(in, inter);
    for (int i = 0; i < n; i++) {
        sum[0][i + 1] = (sum[0][i] + d[i]);
        sum[1][i + 1] = (sum[1][i] + in[i]);
    }
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        ans = max(ans, sum[0][i] + sum[1][n - i]);
    }
    cout << ans << endl;
    return 0;
}