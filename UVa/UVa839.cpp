#include <bits/stdc++.h>

using namespace std;

bool solve(int &g) {
    int wr, dr, wl, dl;
    cin >> wl >> dl >> wr >> dr;
    bool bl = true, br = true;
    if (!wl) bl = solve(wl);
    if (!wr) br = solve(wr);
    g = wl + wr;
    return bl && br && (wr * dr == wl * dl);
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int g = 0;
        cout << (solve(g) ? "YES" : "NO") << endl << (n ? "\n" : "");
    }
    return 0;
}
