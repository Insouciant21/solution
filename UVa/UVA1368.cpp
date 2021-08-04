#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        int m, n;
        cin >> m >> n;
        string k[50];
        string ans;
        int res = 0;
        for (int i = 0; i < m; i++)
            cin >> k[i];
        for (int i = 0; i < n; i++) {
            int A = 0, G = 0, T = 0, C = 0;
            for (int j = 0; j < m; j++) {
                if (k[j][i] == 'A')
                    A++;
                if (k[j][i] == 'G')
                    G++;
                if (k[j][i] == 'T')
                    T++;
                if (k[j][i] == 'C')
                    C++;
            }
            int maxn = max(max(A, G), max(T, C));
            if (A == maxn)
                ans += 'A', res += (m - A);
            else if (C == maxn)
                ans += 'C', res += (m - C);
            else if (G == maxn)
                ans += 'G', res += (m - G);
            else if (T == maxn)
                ans += 'T', res += (m - T);
        }
        cout << ans << endl << res << endl;
    }
    return 0;
}
