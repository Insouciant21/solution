/*
 *  Problem: UVA11488
 *  Author: Insouciant21
 *  Date: 2022/4/14
 */

#include <bits/stdc++.h>

using namespace std;

const int maxNode = 250020;
const int sigmaSize = 2;

struct Trie {
    int ch[maxNode][sigmaSize];
    bool node[maxNode];
    struct Val {
        int depth, cnt;
    } v[maxNode];
    int size = 0;
    Trie() {
        size = 1;
        memset(ch[0], 0, sizeof ch[0]);
    }

    void clear() {
        memset(ch, 0, sizeof ch);
        memset(v, 0, sizeof v);
        ans = 0;
        size = 1;
    }

    static int idx(char c) { return (c == '0') ? 0 : 1; }

    void insert(const string &s) {
        int u = 0;
        int depth = 0;
        for (char i : s) {
            int c = idx(i);
            if (!ch[u][c]) {
                memset(ch[size], 0, sizeof ch[size]);
                node[size] = 0;
                ch[u][c] = size++;
            }
            v[u].cnt++;
            v[u].depth = depth++;
            u = ch[u][c];
        }
        node[u] = 1;
        v[u].cnt++;
        v[u].depth = s.length();
    }

    int ans = 0;

    void solve(int u) {
        ans = max(ans, v[u].depth * v[u].cnt);
        // printf("u dep u %d %d %d\n", u, v[u].depth, v[u].cnt);
        if (ch[u][0]) solve(ch[u][0]);
        if (ch[u][1]) solve(ch[u][1]);
    }
};

Trie f;

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        f.clear();
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            f.insert(s);
        }
        f.solve(0);
        cout << f.ans << endl;
    }
    return 0;
}
