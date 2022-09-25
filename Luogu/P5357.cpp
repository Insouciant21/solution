#include <bits/stdc++.h>

using namespace std;

const int maxn = 2 * int(1e6) + 10, sigma = 26;
vector<string> ss;
struct AC {
    int ch[maxn][sigma] {};
    int val[maxn] {}, last[maxn] {};
    int f[maxn] {};
    int sz = 0, ans[maxn] {};
    AC() { init(); }
    map<string, int> k;
    map<int, string> rk;
    void init() { sz = 1, fill_n(ch[0], sigma, 0); }
    static int idx(char x) { return x - 'a'; }
    void insert(const string &s) {
        int u = 0;
        for (auto i : s) {
            int c = idx(i);
            if (!ch[u][c]) {
                memset(ch[sz], 0, sizeof ch[sz]);
                val[sz] = 0;
                ch[u][c] = sz++;
            }
            u = ch[u][c];
        }
        val[u] = 1;
        if (!k.count(s)) k[s] = u;
        rk[u] = s;
    }
    void m(int j) {
        if (j) {
            ans[j] += val[j];
            m(last[j]);
        }
    }
    void find(const string &s) {
        int j = 0;
        for (auto i : s) {
            int c = idx(i);
            while (j && !ch[j][c]) j = f[j];
            j = ch[j][c];
            if (j) m(j);
            else if (last[j]) m(last[j]);
        }
    }
    void getFail() {
        queue<int> q;
        f[0] = 0;
        for (int c = 0; c < sigma; c++) {
            int u = ch[0][c];
            if (u) f[u] = 0, q.push(u), last[u] = 0;
        }
        while (!q.empty()) {
            int r = q.front();
            q.pop();
            for (int c = 0; c < sigma; c++) {
                int u = ch[r][c];
                if (!u) {
                    ch[r][c] = ch[f[r]][c];
                    continue;
                }
                q.push(u);
                int v = f[r];
                while (v && !ch[v][c]) v = f[v];
                f[u] = ch[v][c], last[u] = val[f[u]] ? f[u] : last[f[u]];
            }
        }
    }
    void getR() {
        for (auto &s : ss) cout << ans[k[s]] << endl;
    }
} ac;

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        ss.push_back(s);
        ac.insert(s);
    }
    string s;
    cin >> s;
    ac.getFail();
    ac.find(s);
    ac.getR();
}