#include <bits/stdc++.h>

using namespace std;

struct BigInteger {
    static const int BASE = 100000000;
    // int width = 9;
    vector<int> num;
    BigInteger &operator=(const string &p) {
        num.clear();
        int k = 0;
        for (int i = int(p.size()) - 1; i >= 0; i--) {
            k = p[i] - '0' + k * 10;
            if (k >= BASE) {
                int g = 0;
                while (k != 0) {
                    g = g * 10 + k % 10;
                    k /= 10;
                }
                num.push_back(g);
            }
        }
        if (k != 0) {
            int g = 0;
            while (k != 0) {
                g = g * 10 + k % 10;
                k /= 10;
            }
            num.push_back(g);
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
    for (int i = int(x.num.size() - 1); i >= 0; i--) {
        res += to_string(x.num[i]);
    }
    out << res;
    return out;
}

BigInteger operator+(BigInteger a, BigInteger b) {
    BigInteger ans;
    size_t pointerA = a.num.size() - 1;
    size_t pointerB = b.num.size() - 1;
    while (pointerA >= 0 && pointerB >= 0) {
        int k = a.num[pointerA] + b.num[pointerB];
        ans.num.push_back(k);
        pointerA--, pointerB--;
    }
    for (int i = int(ans.num.size() - 1); i > 0; i--) {
        ans.num[i - 1] += ans.num[i] / (BigInteger::BASE * 10);
        ans.num[i] %= (BigInteger::BASE * 10);
    }
    if (ans.num[0] > BigInteger::BASE * 10) {
        ans.num.insert(ans.num.begin(), ans.num[0] / (BigInteger::BASE * 10));
        ans.num[1] %= (BigInteger::BASE * 10);
    }
    return ans;
}

#ifndef SOLUTION_ALGORITHM_BIGINTEGER_H
#define SOLUTION_ALGORITHM_BIGINTEGER_H

#endif // SOLUTION_ALGORITHM_BIGINTEGER_H
