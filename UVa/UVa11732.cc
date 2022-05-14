/*
 *  Problem: UVa11732
 *  Author: Insouciant21
 *  Date: 2022/4/21
 */

#include <bits/stdc++.h>

using namespace std;

const int maxNode = 4000010;
const int sigmaSize = 26 * 2 + 15;

struct Trie {
    int ch[maxNode][sigmaSize] {};
    struct Node {
        bool isWord = false;
        int val = 0;
        int depth = 0;
    } node[maxNode] {};

    int size = 0;
    Trie() {
        memset(ch, 0, sizeof ch);
        size++;
        ch[0][0] = 0;
        node[0].val = 0;
        node[0].depth = 0;
    }

    static int idx(char c) {
        if (isdigit(c)) return c - '0';
        if (islower(c)) return c - 'a' + 10;
        if (isupper(c)) return c - 'A' + 36;
        return 66;
    }

    void clean() {
        memset(ch, 0, sizeof ch);
        memset(node, 0, sizeof node);
        size = 1;
    }

    void insert(const string &s) {
        int u = 0;
        for (int i = 0; i < s.length(); i++) {
            int c = idx(s[i]);
            if (!ch[u][c]) {
                node[size].isWord = false;
                ch[u][c] = size++;
            }
            u = ch[u][c];
            node[u].depth = i + 1;
            node[u].val++;
        }
        node[u].isWord = true;
        node[0].val++;
    }

    void remove(const string &s) {
        int u = 0;
        for (char i : s) {
            int c = idx(i);
            node[u].val--;
            u = ch[u][c];
        }
        node[u].val--;
    }

    long long review() {
        long long ret = 0;
        int u = 0;
        for (char i : s) {
            int c = idx(i);
            ret += (node[u].val - node[ch[u][c]].val) * (node[ch[u][c]].depth + 1) * 2 - 1;
            u = ch[u][c];
        }
        return ret;
    }
};

vector<string> g;

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int n;
    Trie f;
    int kase = 0;
    while (true) {
        cin >> n;
        if (n == 0) break;
        kase++;
        long long ans = 0;
        g.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> g[i];
            g[i] += '$';
            f.insert(g[i]);
        }
        ans = f.review();
        printf("Case %d: %lld\n", kase, ans);
        f.clean();
    }
    return 0;
}
