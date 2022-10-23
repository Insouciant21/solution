#include <bits/stdc++.h>

using namespace std;

const int maxn = 6e5;
const double g = 9.8;

int n, m;

struct Missile {
    int x, y;
    int v;
    double landTime() { return sqrt(2 * y / g); }
} a[maxn];

map<int, vector<int>> k;

struct cmp {
    bool operator()(int x, int b) { return a[x].x < a[b].x; }
};

int v[maxn];

void merge(vector<int> &f, int l, int r, int mid, int T[]) {
    int pl = l, pr = mid;
    for (int i = l; i < r; i++) {
        if (pr == r || (pl < mid && a[f[pl]].v < a[f[pr]].v)) T[i] = f[pl++];
        else {
            T[i] = f[pr];
            v[f[pr++]] += mid - pl;
        }
    }
    for (int i = l; i < r; i++) f[i] = T[i];
}

void merge_sort(int l, int r, int T[], vector<int> &f) {
    if (r - l <= 1) return;
    int mid = l + ((r - l) >> 1);
    merge_sort(l, mid, T, f);
    merge_sort(mid, r, T, f);
    merge(f, l, r, mid, T);
}

int x[maxn];
int t[maxn];

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y >> a[i].v;
        k[a[i].y].push_back(i);
    }
    for (int i = 1; i <= n; i++) cin >> x[i];
    long long ans = 0;
    for (pair<const int, vector<int>> i : k) {
        memset(t, 0, sizeof t);
        sort(i.second.begin(), i.second.end(), cmp());
        merge_sort(0, int(i.second.size()), t, i.second);
        for (int j : i.second) {
            ans += v[j];
            v[j] = (v[j] - x[j] > 0) ? x[j] : v[j];
        }
    }
    sort(v + 1, v + 1 + n, greater<int>());
    for (int i = 1; i <= m; i++) ans -= v[i];
    cout << ans << endl;
    return 0;
}