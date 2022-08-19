#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCALENV
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    int T;
    cin >> T;
    while (T--) {
        int a[6];
        vector<int> p({1, 2, 3, 4, 5});
        bool s = false;
        for (int i = 1; i < 5; i++) cin >> a[i];
        for (int i = 0; i <= 9; i++) {
            a[5] = i;
            bool flag = false;
            do {
                if (a[p[0]] - 1 == a[p[1]] && a[p[1]] == a[p[2]] + 1 && a[p[3]] == a[p[4]]) {
                    flag = true;
                    break;
                }
            } while (next_permutation(p.begin(), p.end()));
            if (flag) {
                puts("1");
                s = true;
                break;
            }
        }
        if (!s) puts("0");
    }
}
