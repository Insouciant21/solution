#include <bits/stdc++.h>

using namespace std;

int process(string s) {
    if (s.length() == 4) return 0;
    s = s.substr(4), s.pop_back();
    return stoi(s);
}

struct O {
    const int N = 0x3f3f3f;
    char var;
    int f, t;
    int complex() {
        if (f == N && t != N) return -1;
        if (f == N && t == N) return 0;
        if (f != N && t == N) return 1;
        if (f != N && t != N) return (t >= f) - 1;
    }
    O() {
        var = 'n';
        f = t = N;
    }
    O(string s) {
        string a, b;
        s = s.substr(2);
        stringstream ss(s);
        ss >> a;
        var = a[0];
        ss >> a >> b;
        if (a == "n") f = N;
        else f = stoi(a);
        if (b == "n") t = N;
        else t = stoi(b);
    }
};

int main() {
#ifdef LOCALENV
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    int T;
    cin >> T;
    while (T--) {
        int line;
        cin >> line;
        string s;
        cin >> s;
        int cpx = process(s);
        stack<O> x;
        bool fail = false;
        bool ne = false;
        int ans[200];
        memset(ans, 0, sizeof ans);
        getchar();
        bool vis[250];
        memset(vis, 0, sizeof vis);
        int res = -0x3f3f3f;
        while (line--) {
            getline(cin, s);
            if (fail) continue;
            if (s == "E") {
                if (x.empty()) {
                    fail = true;
                    continue;
                }
                else {
                    ans[x.size()] = max(ans[x.size()], x.top().complex() + ans[x.size() + 1]);
                    if (x.top().complex() == -1) ans[x.size()] = 0;
                    if (x.size() == 1) res = max(res, ans[1]), ans[1] = 0;
                    vis[x.top().var] = false;
                    for (int i = x.size() + 1; i < 200; i++) ans[i] = 0;
                    x.pop();
                    continue;
                }
            }
            O g(s);
            if (vis[g.var]) {
                fail = true;
                continue;
            }
            vis[g.var] = true;
            x.push(g);
        }
        if (!x.empty()) fail = true;
        if (fail) cout << "ERR" << endl;
        else cout << ((res == cpx) ? "Yes" : "No") << endl;
    }
}