/*
 *  Problem: UVA11488
 *  Author: Insouciant21
 *  Date: 2022/4/14
 *  wait
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
    }

    static int idx(char c) { return c - 'a'; }

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
            u = ch[u][c];
            depth++;
        }
        node[u] = 1;
    }

    int checkSizeOf(int pos) { return (ch[pos][0] == 1) + (ch[pos][1] == 1); }
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
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            f.insert(s);
        }
        solve(0, 0);
    }
    return 0;
}
