/*
  Problem: test
  Time: 2020/11/18 20:23:20
  Author: Insouciant21
  Status: NULL
*/

// #include "Algorithm/BigInteger.h"
#include <bits/stdc++.h>

using namespace std;

int n, m;

struct BigInteger {
    static const int BASE = 100000000;
    int width = 9;
    vector<int> num;
    bool nega {};
    BigInteger &operator=(string p) {
        num.clear();
        if (p[0] == '-') {
            nega = true;
            p.erase(0, 1);
        }
        int len = int(p.length() - 1) / width + 1;
        for (int i = 0; i < len; i++) {
            int k = 0;
            int ed = int(p.length()) - i * width;
            int st = max(0, ed - width);
            sscanf(p.substr(st, ed - st).c_str(), "%d", &k);
            num.push_back(k);
        }
        return *this;
    }
};

istream &operator>>(istream &in, BigInteger &x) {
    string p;
    if (!(in >> p)) return in;
    x = p;
    return in;
}

ostream &operator<<(ostream &out, const BigInteger &x) {
    string res;
    if (x.nega) out << '-';
    for (int i = int(x.num.size() - 1); i >= 0; i--) res += to_string(x.num[i]);
    out << res;
    return out;
}

bool operator<(const BigInteger &a, const BigInteger &b) {
    if (a.num.size() < b.num.size()) return true;
    else if (a.num.size() > b.num.size()) return false;
    for (int i = int(a.num.size() - 1); i >= 0; i--)
        if (a.num[i] != b.num[i]) return a.num[i] < b.num[i];
    return false;
}

bool operator>(const BigInteger &a, const BigInteger &b) {
    return b < a;
}
bool operator!=(const BigInteger &a, const BigInteger &b) {
    return a < b || a > b;
}
bool operator<=(const BigInteger &a, const BigInteger &b) {
    return !(a > b);
}
bool operator>=(const BigInteger &a, const BigInteger &b) {
    return !(a < b);
}
bool operator==(const BigInteger &a, const BigInteger &b) {
    return a <= b && a >= b;
}

BigInteger operator+(BigInteger a, BigInteger b) {
    BigInteger res;
    if (a.nega && b.nega) res.nega = true;
    a.num.resize(max(a.num.size(), b.num.size()));
    b.num.resize(max(a.num.size(), b.num.size()));
    for (int i = 0; i < max(a.num.size(), b.num.size()); i++) res.num.push_back(a.num[i] + b.num[i]);
    for (int i = 0; i < res.num.size(); i++) {
        if (res.num[i] < BigInteger::BASE * 10) continue;
        if (i != res.num.size() - 1) res.num[i + 1] += res.num[i] % (BigInteger::BASE * 10);
        else res.num.push_back(res.num[i] % (BigInteger::BASE * 10));
        res.num[i] %= (BigInteger::BASE * 10);
    }
    return res;
}

BigInteger operator-(BigInteger a, BigInteger b) {
    BigInteger res;
    if (a < b) {
        swap(a, b);
        res.nega = true;
    }
    for (int i = 0; i < b.num.size(); i++) {
        int k = a.num[i] - b.num[i];
        if (k < 0) {
            k = a.num[i] * 10 - b.num[i];
            a.num[i + 1]--;
        }
        res.num.push_back(k);
    }
    return res;
}

int main() {
    BigInteger a, b, c;
    while (cin >> a >> b >> c) {
        BigInteger k = a + b;
        if (k != c) {
            cout << a << endl << b << endl;
            cout << c << endl << k << endl;
            return 0;
        }
    }
    return 0;
}