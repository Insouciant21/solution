/*
  Problem: UVA495
  Time: 2020/10/03 22:36:42
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

const int LEN = 1100;

class BigInteger {
   private:
    int digit[1101];

   public:
    BigInteger() {
        for (int i = 0; i <= LEN; i++)
            digit[i] = 0;
    }
    BigInteger(int x) {
        for (int i = 0; i <= LEN; i++)
            digit[i] = 0;
        int t = x;
        int length = 1;
        int len = 0;
        while (t) {
            t /= 10;
            length *= 10;
            len++;
        }
        while (length) {
            digit[len] = x / length;
            len--;
            x %= length;
            length /= 10;
        }
    }
    int getLength() {
        for (int i = LEN; i >= 0; i--)
            if (digit[i] != 0)
                return i;
        return 0;
    }
    friend BigInteger operator+(BigInteger x, BigInteger y);
    friend bool operator!=(BigInteger x, BigInteger y);
    friend void print(int n, BigInteger &);
};

BigInteger operator+(BigInteger x, BigInteger y) {
    BigInteger res;
    for (int i = 0; i <= LEN; i++) {
        res.digit[i] += x.digit[i] + y.digit[i];
        if (res.digit[i] >= 10) {
            res.digit[i + 1]++;
            res.digit[i] -= 10;
        }
    }
    return res;
}

void print(int n, BigInteger &res) {
    printf("The Fibonacci number for %d is ", n);
    for (int i = res.getLength(); i >= 0; i--)
        printf("%d", res.digit[i]);
    printf("\n");
}

pair<int, pair<BigInteger, BigInteger>> mem[5001];

int main() {
    int n;
    while (cin >> n) {
        BigInteger a(0), b(1), c;
        int st;
        for (int i = n; i >= 0; i--) {
            if (mem[i].first == 1) {
                a = mem[i].second.first;
                b = mem[i].second.second;
                st = i;
                break;
            }
        }
        for (int i = st + 1; i <= n; i++) {
            swap(a, b);
            b = a + b;
            mem[i].second.first = a, mem[i].second.second = b;
            mem[i].first = 1;
        }
        print(n, a);
    }
    return 0;
}