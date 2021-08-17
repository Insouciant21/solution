#include <bits/stdc++.h>

using namespace std;

int getDayM(int y, int m) {
    switch (m) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12: return 31;
        case 2:
            if (y % 4 == 0 && y % 100 != 0) return 29;
            if (y % 400 == 0) return 29;
            return 28;

        default: return 30;
    }
}

int main() {
    while (true) {
        int Y, M, D, h, m, s;
        scanf("%d", &Y);
        if (Y == 0) return 0;
        scanf("/%d/%d %d:%d:%d", &M, &D, &h, &m, &s);
        bitset<32> in;
        cin >> in;
        long long sec = in.to_ullong();
        s += sec;
        m += s / 60;
        s %= 60;
        h += m / 60;
        m %= 60;
        D += h / 24;
        h %= 24;
        while (D > getDayM(Y, M)) {
            D -= getDayM(Y, M);
            M++;
            if (M == 13) {
                Y++;
                M = 1;
            }
        }
        printf("%04d/%02d/%02d %02d:%02d:%02d\n", Y, M, D, h, m, s);
    }
    return 0;
}