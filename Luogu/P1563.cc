#include <bits/stdc++.h>

using namespace std;

struct Man {
    int d;
    string pro;
};

int n, m;

Man q[100010];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> q[i].d >> q[i].pro;
    int p = 0;
    while (m--) {
        int d, s;
        cin >> d >> s;
        d = d ^ q[p].d;
        if (d == 0) p = (p - s + n) % (n);
        if (d == 1) p = (p + s) % (n);
    }
    cout << q[p].pro << endl;
}