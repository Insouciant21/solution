#include <bits/stdc++.h>

using namespace std;

const int LEN = 10000;

class BigInteger {
   private:
    int digit[10001];

   public:
    BigInteger() {
        for (int i = 0; i <= LEN; i++) digit[i] = 0;
    }
    int getLength() {
        for (int i = LEN; i >= 0; i--)
            if (digit[i] != 0)
                return i;
        return 0;
    }
    friend BigInteger operator+(BigInteger x, BigInteger y);
    friend BigInteger operator-(BigInteger x, BigInteger y);
    friend BigInteger operator*(BigInteger x, int y);
    friend BigInteger operator*(BigInteger x, BigInteger y);
    friend istream &operator>>(istream &in, BigInteger &r);
    friend ostream &operator<<(ostream &out, BigInteger &res);
    friend ostream &operator<<(ostream &out, BigInteger &&res);
};

BigInteger operator+(BigInteger x, BigInteger y) {
    BigInteger res;
    for (int i = 0; i <= LEN; i++) {
        res.digit[i] += x.digit[i] + y.digit[i];
        if (res.digit[i] > 10) {
            res.digit[i + 1]++;
            res.digit[i] -= 10;
        }
    }
    return res;
}

BigInteger operator-(BigInteger x, BigInteger y) {
    BigInteger res;
    bool nega = false;
    for (int i = LEN; i >= 0; i--) {
        if (x.digit[i] < y.digit[i]) {
            nega = true;
            swap(x, y);
            break;
        }
        if (x.digit[i] > y.digit[i])
            break;
    }
    for (int i = 0; i <= LEN; i++) {
        res.digit[i] += x.digit[i] - y.digit[i];
        if (res.digit[i] < 0) {
            res.digit[i + 1]--;
            res.digit[i] += 10;
        }
    }
    if (nega) {
        for (int i = LEN; i >= 0; i--) {
            if (res.digit[i] != 0) {
                res.digit[i] = -res.digit[i];
                break;
            }
        }
    }
    return res;
}

BigInteger operator*(BigInteger x, int y) {
    BigInteger res;
    bool nega = 0;
    for (int i = 0; i <= LEN; i++) {
        res.digit[i] += x.digit[i] * y;
        if (res.digit[i] >= 10) {
            res.digit[i + 1] = res.digit[i] / 10;
            res.digit[i] %= 10;
        }
        if (res.digit[i] < 0) {
            res.digit[i] = abs(res.digit[i]);
            nega = 1;
        }
    }
    if (nega) {
        for (int i = LEN; i >= 0; i--) {
            if (res.digit[i] != 0) {
                res.digit[i] = -res.digit[i];
                break;
            }
        }
    }
    return res;
}

BigInteger operator*(BigInteger x, BigInteger y) {
    BigInteger res;
    bool nega = 0;
    for (int i = 0; i <= LEN; i++) {
        for (int j = 0; j <= i; j++) res.digit[i] += x.digit[j] * y.digit[i - j];
        if (res.digit[i] >= 10) {
            res.digit[i + 1] += res.digit[i] / 10;
            res.digit[i] %= 10;
        }
        if (res.digit[i] < 0) {
            res.digit[i] = abs(res.digit[i]);
            nega = 1;
        }
    }
    if (nega) {
        for (int i = LEN; i >= 0; i--) {
            if (res.digit[i] != 0) {
                res.digit[i] = -res.digit[i];
                break;
            }
        }
    }
    return res;
}

istream &operator>>(istream &in, BigInteger &r) {
    string res;
    in >> res;
    bool nega = false;
    if (res[0] == '-')
        res.erase(0, 1);
    int x = res.length() - 1, y = res.length() - 1;
    for (int i = 0; i < res.length(); i++) r.digit[x--] = res[i] - '0';
    if (nega)
        r.digit[y] = -r.digit[y];
    return in;
}

ostream &operator<<(ostream &out, BigInteger &res) {
    int len = res.getLength();
    for (int i = len; i >= 0; i--) out << res.digit[i];
    return out;
}

ostream &operator<<(ostream &out, BigInteger &&res) {
    int len = res.getLength();
    for (int i = len; i >= 0; i--) out << res.digit[i];
    return out;
}

int main() {
    BigInteger in1, in2;
    cin >> in1 >> in2;
    cout << in1 + in2 << endl;
    cout << in1 - in2 << endl;
    cout << in1 * in2 << endl;
}