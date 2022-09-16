#include <bits/stdc++.h>

using namespace std;

int n, na, nb;

void inQ(queue<int> &a, int num) {
    vector<int> x;
    for (int i = 0; i < num; i++) {
        int t;
        cin >> t;
        x.push_back(t);
    }
    int cnt = 0;
    for (int p = 0; cnt < n; p++) {
        if (p == x.size()) p = 0;
        a.push(x[p]), cnt++;
    }
}

int G(int l, int r) {
    if (l == r) return -1;
    switch (l) {
        case 0: return r == 1 || r == 4;
        case 1: return r == 2 || r == 4;
        case 2: return r == 0 || r == 3;
        case 3: return r == 0 || r == 1;
        case 4: return r == 2 || r == 3;
        default: break;
    }
}

int main() {
    cin >> n >> na >> nb;

    queue<int> a, b;
    inQ(a, na), inQ(b, nb);
    int A = 0, B = 0;
    while (n--) {
        int d = G(a.front(), b.front());
        a.pop(), b.pop();
        if (d == 1) B++;
        if (d == 0) A++;
    }
    cout << A << " " << B << endl;
}