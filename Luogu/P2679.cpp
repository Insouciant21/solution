#include <bits/stdc++.h>

using namespace std;
int f[1010][201][201][2];
int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    string a, b;
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    cin >> a >> b;
    f[0][0][0][0] = f[1][0][0][0] = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) {
            for(int p=0;p<m;p++) {
                if (a[i] == b[j]) {
                    f[i][j][p][0] = f[i-1][j][p][0]+f[i-1][j][p][1];
                }
                else {}
            }
        }
    }
    return 0;
}
