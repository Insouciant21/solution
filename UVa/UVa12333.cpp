#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

map<string, int> f40;

struct BigInteger {
    static const int BASE = 100000000;
    static const int width = 7;
    vector<int> num;

    static ull lenx(int x) { return to_string(x).length(); }

    void addF40(int s) {
        ull f = lenx(num.back());
        unsigned long long len = f + (num.size() - 1) * 5;
        string ans;
        for (int i = int(num.size() - 1); i >= 0; i--) {
            string res = to_string(num[i]);
            while (res.size() < width && i != int(num.size() - 1)) ans.insert(ans.begin(), '0');
            ans += res;
        }
        cout << ans << endl;
        if (len > 40) ans = ans.substr(0, 40);
        string res;
        for (char an : ans) {
            res += an;
            if (!f40.count(res)) f40[res] = s;
        }
    }
};
BigInteger operator+(BigInteger a, BigInteger b) {
    BigInteger res;
    a.num.resize(max(a.num.size(), b.num.size()));
    b.num.resize(max(a.num.size(), b.num.size()));
    for (int i = 0; i < max(a.num.size(), b.num.size()); i++) res.num.push_back(a.num[i] + b.num[i]);
    for (int i = 0; i < res.num.size(); i++) {
        if (res.num[i] < BigInteger::BASE) continue;
        if (i != res.num.size() - 1) res.num[i + 1] += res.num[i] / (BigInteger::BASE);
        else res.num.push_back(res.num[i] / (BigInteger::BASE));
        res.num[i] %= (BigInteger::BASE);
    }
    return res;
}
ostream &operator<<(ostream &o, BigInteger &x) {
    for (int i = int(x.num.size() - 1); i >= 0; i--) {
        string ans = to_string(x.num[i]);
        while (ans.size() < BigInteger::width && i != int(x.num.size() - 1)) ans.insert(ans.begin(), '0');
        o << ans;
    }
    return o;
}

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int k = 0;
    cin >> k;
    BigInteger a, b;
    a.num.push_back(1), b.num.push_back(1);
    a.addF40(0), b.addF40(1);
    for (int i = 2; i <= k; i++) {
        a = a + b;
        swap(a, b);
        cout << "f " << b << endl;
        if (i == 120) {
            cout << "caught" << endl;
            int x = 1;
        }
        b.addF40(i);
    }
    int x;
    cin >> x;
    for (int i = 1; i <= x; i++) {
        string q;
        cin >> q;
        if (!f40.count(q)) printf("Case #%d: -1\n", i);
        else printf("Case #%d: %d\n", i, f40[q]);
    }
    return 0;
}