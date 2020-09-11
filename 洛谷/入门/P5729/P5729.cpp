#include <bits/stdc++.h>

using namespace std;

struct pos {
    int xb, yb, zb;
    int xe, ye, ze;
};

bool cube[21][21][21];
int w, x, h;
int q;

int main() {
    cin >> w >> x >> h;
    cin >> q;
    for (int i = 1; i <= w; i++) {
        for (int j = 1; j <= x; j++) {
            for (int y = 1; y <= h; y++) {
                cube[i][j][y] = true;
            }
        }
    }
    pos t;
    for (int i = 0; i < q; i++) {
        cin >> t.xb >> t.yb >> t.zb >> t.xe >> t.ye >> t.ze;
        for (int m = t.xb; m <= t.xe; m++) {
            for (int n = t.yb; n <= t.ye; n++) {
                for (int p = t.zb; p <= t.ze; p++) {
                    cube[m][n][p] = false;
                }
            }
        }
    }
    int ans = 0;
	for (int i = 1; i <= w; i++) {
		for (int j = 1; j <= x; j++) {
			for (int y = 1; y <= h; y++) {
                if (cube[i][j][y]) ans++;
			}
		}
	}
    cout << ans << endl;
    return 0;
}
