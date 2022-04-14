/*
 *  Problem: P2580
 *  Author: Insouciant21
 *  Date: 2022/4/14
 *  Trie
 */

#include <bits/stdc++.h>

using namespace std;

const int maxNode = 5 * int(1e5) + 3;
const int sigma_size = 26;

struct Trie {
    int ch[maxNode][sigma_size];
    int val[maxNode];
    int size;
    Trie() {
        size = 1;
        memset(ch[0], 0, sizeof ch[0]);
    }
    static int idx(char c) { return c - 'a'; }

    void insert(const string &s) {
        int u = 0;
        for (char i : s) {
            int c = idx(i);
            if (!ch[u][c]) {
                memset(ch[size], 0, sizeof ch[size]);
                val[size] = 0;
                ch[u][c] = size++;
            }
            u = ch[u][c];
        }
        val[u] = 1;
    }

    bool query(const string &s) {
        int u = 0, p = 0;
        while (p != s.size()) {
            int c = idx(s[p]);
            if (!ch[u][c]) return false;
            u = ch[u][c], p++;
        }
        return val[u];
    }
};

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int n, m;
    Trie a, b;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        a.insert(s);
    }
    cin >> m;
    while (m--) {
        string s;
        cin >> s;
        bool f = a.query(s);
        if (!f) {
            cout << "WRONG" << endl;
            continue;
        }
        f = b.query(s);
        if (f)
            cout << "REPEAT" << endl;
        else {
            cout << "OK" << endl;
            b.insert(s);
        }
    }
    return 0;
}
