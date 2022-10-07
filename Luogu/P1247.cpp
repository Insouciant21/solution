#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int k;
    vector<int> n;
    cin >> k;
    int sum = 0;
    for (int i = 0, t; i < k; i++) {
        cin >> t;
        n.push_back(t);
        sum ^= t;
    }
    if (!sum) cout << "lose" << endl;
    else {
        int ans[2];
        for (int i = 0; i < k; i++) {
            sum ^= n[i];
            bool flag = false;
            for (int j = 1; j <= n[i]; j++) {
                sum ^= (n[i] - j);
                if (!sum) {
                    flag = true;
                    ans[0] = i, ans[1] = j;
                    break;
                }
                sum ^= (n[i] - j);
            }
            if (flag) break;
            sum ^= n[i];
        }
        cout << ans[1] << " " << ans[0] + 1 << endl;
        for (int i = 0; i < k; i++) cout << (i == ans[0] ? n[i] - ans[1] : n[i]) << " ";
    }
    return 0;
}