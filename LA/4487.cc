/*
 *  Problem: 4487
 *  Author: Insouciant21
 *  Date: 2022/4/14
 *  Later--------
 */

#include <bits/stdc++.h>

using namespace std;

int x[20020];
bool xp[20020];

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int n, Q;
    while (true) {
        cin >> n >> Q;
        if (n == Q && n == 0) break;
        int p = 0;
        while (Q--) {
            string s;
            getline(cin, s);
            stringstream ss(s);
            char c;
            ss >> c;
            if (c == 'I') {
                p++;
                int a[3], cnt = 0;
                while (!ss.eof()) ss >> a[cnt++];
                if (cnt == 3) {
                    if (!xp[a[0]]) x[a[0]] = a[1], xp[a[0]] = true;
                    else if (x[a[0]] != a[1]) printf("The first %d facts are conflicting.\n", p);
                }
                else {
                    if()
                }
            }
        }
    }
    return 0;
}
