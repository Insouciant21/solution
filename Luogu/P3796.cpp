#include <bits/stdc++.h>

using namespace std;
const int SIGMA = 26, MAXN = int(1e6) + 10;
int n, ans[MAXN];
map<int, string> k;

struct AC {
    int ch[MAXN][SIGMA] {};
    int f[MAXN] {};
    int val[MAXN] {};
    int last[MAXN] {};
    int sz {};
    AC() { init(); }
    void init() {
        sz = 1, fill_n(ch[0], SIGMA, 0);
        memset(ans, 0, sizeof ans);
        k.clear();
    }
    static int idx(char c) { return c - 'a'; }
    void insert(const string &s) {
        int u = 0;
        for (char i : s) {
            int c = idx(i);
            if (!ch[u][c]) {
                memset(ch[sz], 0, sizeof ch[sz]);
                val[sz] = 0;
                ch[u][c] = sz++;
            }
            u = ch[u][c];
        }
        val[u] = 1;
        k[u] = s;
    }

    void mark(int j) {
        if (j) {
            if (val[j]) ans[j]++;
            mark(last[j]);
        }
    }

    void find(const string &T) {
        int j = 0;
        for (char i : T) {
            int c = idx(i);
            while (j && !ch[j][c]) j = f[j];
            j = ch[j][c];
            if (j) mark(j);
            else if (last[j]) mark(last[j]);
        }
    }

    void getFail() {
        queue<int> q;
        f[0] = 0;
        for (int c = 0; c < SIGMA; c++) {
            int u = ch[0][c];
            if (u) f[u] = 0, q.push(u), last[u] = 0;
        }
        while (!q.empty()) {
            int r = q.front();
            q.pop();
            for (int c = 0; c < SIGMA; c++) {
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

    void getRes() {
        int mxm = -1;
        vector<int> pos;
        for (int i = 1; i <= sz; i++) mxm = max(mxm, ans[i] * val[i]);
        for (int i = 1; i <= sz; i++)
            if (ans[i] == mxm) pos.push_back(i);
        cout << mxm << endl;
        for (int i : pos) cout << k[i] << endl;
    }
};

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    while (true) {
        cin >> n;
        if (n == 0) break;
        AC ac;
        ac.init();
        for (int i = 1; i <= n; i++) {
            string s;
            cin >> s;
            ac.insert(s);
        }
        ac.getFail();
        string t;
        cin >> t;
        ac.find(t);
        ac.getRes();
    }
    return 0;
}