#include <bits/stdc++.h>

using namespace std;

const int maxn = 510;

int ans[maxn];

int n, sure = 0;

int ask(int i) {
    printf("? 1 %d", i);
    cout << endl;
    int x;
    cin >> x;
    return x;
}

void setV(int i) {
    printf("? 2 %d", i);
    cout << endl;
}

void solve(int g) {
    int l = 1, r = n;
    int m = (l + r) >> 1;
    while (true) {
        int x = ask(m);
        if (x == g)
            r = m;
        else
            l = m + 1;
        if (l == r) {
            m = l;
            break;
        }
        m = (l + r) >> 1;
    }
    setV(m);
    ans[m] = n - sure;
}

void printAns() {
    printf("!");
    for (int i = 1; i <= n; i++) printf(" %d", ans[i]);
    cout << endl;
}

int main() {
    int t = 0;
    cin >> t;
    while (t--) {
        cin >> n;
        while (sure != n) {
            solve(ask(n));
            sure++;
        }
        printAns();
    }
}
